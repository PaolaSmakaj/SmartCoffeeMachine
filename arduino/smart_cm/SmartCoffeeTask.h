#ifndef SMART_COFFEE_TASK
#define SMART_COFFEE_TASK

#include "Task.h"
#include "Timer.h"
#include "Pir.h"
#include "Sonar.h"
#include "Button.h"
#include "Pot.h"
#include "Led.h"
#include "MsgService.h"

class SmartCoffeeTask: public Task {
public:

    SmartCoffeeTask();
    void init(int period);
    void tick();

private:
    Pir* pir;
    Sonar* sDist;
    Button* t1;
    Pot* pot;
    Led* l1;
    Led* l2;
    Led* l3;
    int detectionTime;
    int afk;
    bool coffee_taken = false;
    int coffee_num = 3;
    const int DT1 = 1000;
    const int DT2a = 5000;
    const int DT2b = 5000;
    const int DT3 = 3000;
    const int DT4 = 5000;
    const float DIST1 = 0.3;
    const float DIST2 = 0.1;
    const int NMAX = 3;
    int sugar;

    enum { STANDBY, ON, READY, COFFEE, COFFEE_READY, MAINTENANCE } state;
};

#endif
