#ifndef LED_LIB
#define LED_LIB

class Led {
public:
  Led(int pin);
  void switchOn();
  void switchOff();
protected:
  int pin;
};

#endif
