#ifndef BUTTON_LIB
#define BUTTON_LIB

class Button {
 public:
  Button(int pin);
  bool isPressed();
private:
  int pin;
};

#endif
