#ifndef TIMER_LIB
#define TIMER_LIB

class Timer {

public:
  Timer();
  void setupFreq(int freq);
  /* period in ms */
  void setupPeriod(int period);
  void waitForNextTick();

};


#endif
