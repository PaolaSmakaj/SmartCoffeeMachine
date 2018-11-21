#ifndef SONAR_LIB
#define SONAR_LIB

class Sonar {

public:
  Sonar(int echoPin, int trigPin);
  float getDistance();

private:
    const float vs = 331.5 + 0.6*20;
    int echoPin, trigPin;
};

#endif
