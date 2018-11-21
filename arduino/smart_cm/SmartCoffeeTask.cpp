#include "SmartCoffeeTask.h"
#include "pinconfig.h"
#include "Led.h"
#include "Logger.h"

extern bool refilled; 

SmartCoffeeTask::SmartCoffeeTask() {
    pir = new Pir(PIR_PIN);
    t1 = new Button(T1_PIN);
    sDist = new Sonar(SD_ECHO, SD_TRIG);
    pot = new Pot(POT_PIN);
    l1 = new Led(L1_PIN);
    l2 = new Led(L2_PIN);
    l3 = new Led(L3_PIN);
}

void SmartCoffeeTask::init(int period) {
    Task::init(period);
    state = STANDBY;
}

void SmartCoffeeTask::tick() {
    switch(state) {
        case STANDBY: {
            if(pir->isDetected()) {
                detectionTime = 0;
                afk = 0;
                state = ON;
                sugar = 0;
            }
            break;
        }
        case ON: {
            if(sDist->getDistance() <= DIST1) {
                detectionTime += myPeriod;
                afk = 0;
            }
            else if(pir->isDetected() == false){
                detectionTime = 0;
                afk += myPeriod;
            }
            if (detectionTime >= DT1) {
                Logger.log("Welcome! Sugar level: "+String(sugar));
                state = READY;
            }
            else if (afk >= DT2b) {
                detectionTime = 0;
                afk = 0;
                state = STANDBY;
            }
            break;
        }
        case READY: {
            if(afk >= DT2a) {
                afk = 0;
                state = ON;
            }

            if(sDist->getDistance() <= DIST1) {
                afk += myPeriod;
            } else {
                afk = 0;
            }

            if (sugar != pot->getSugar()) {
                sugar = pot->getSugar();
                Logger.log("Welcome! Sugar level: "+String(sugar));
            }

            if(t1->isPressed()) {
                Logger.log("Making a coffee");
                afk = 0;
                detectionTime = 0;
                state = COFFEE;
            }
            break;
        }
        case COFFEE: {
            l1->switchOn();
            afk += myPeriod;
            if(afk >= DT3/3)
                l2->switchOn();
            if(afk >= 2*DT3/3)
                l3->switchOn();
            if(afk >= DT3) {
                l1->switchOff();
                l2->switchOff();
                l3->switchOff();
                afk = 0;
                Logger.log("The coffee is ready");
                state = COFFEE_READY;
            }
            break;
        }
        case COFFEE_READY: {
            if(sDist->getDistance() <= DIST2) {
                coffee_taken = true;
            }
            else {
                afk += myPeriod;
            }

            if(afk >= DT4 || coffee_taken) {
                afk = 0;
                coffee_num--;
                if(coffee_num == 0) {
                    Logger.log("No more coffee. Waiting for recharge");
                    state = MAINTENANCE;
                }
                else {
                    Logger.log("Welcome! Sugar level: "+String(sugar));
                    state = READY;
                }
            }
            break;
        }
        case MAINTENANCE: {
            if(refilled == true) {
                coffee_num = NMAX;
                refilled = false;
                Logger.log("Welcome! Sugar level: "+String(sugar));
                state = READY;
            }
            break;
        }
    }
}
