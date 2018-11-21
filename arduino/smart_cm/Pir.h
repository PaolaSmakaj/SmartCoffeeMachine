#ifndef PIR_LIB
#define PIR_LIB

class Pir {
public: 
  Pir(int pin);
  bool isDetected();

private:
  int pin;
};

#endif
