#ifndef COFFEECOMMTASK_LIB
#define COFFEECOMMTASK_LIB

#include "Task.h"
#include "MsgService.h"

class CoffeeCommTask: public Task {

public:

  CoffeeCommTask();
  void init(int period);
  void tick();
};

#endif
