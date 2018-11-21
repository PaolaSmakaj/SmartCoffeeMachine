#include "Scheduler.h"
#include "CoffeeCommTask.h"
#include "SmartCoffeeTask.h"
#include "MsgService.h"
Scheduler sched;
bool refilled = false;

void setup() {
    sched.init(50);
    MsgService.init();
    CoffeeCommTask* cct = new CoffeeCommTask();
    cct->init(50);
    sched.addTask(cct);

    SmartCoffeeTask* sct = new SmartCoffeeTask();
    sct->init(50);
    sched.addTask(sct);
}

void loop() {
    sched.schedule();
}
