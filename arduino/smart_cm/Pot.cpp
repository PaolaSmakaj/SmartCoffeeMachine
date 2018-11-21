#include "Pot.h"
#include "Arduino.h"

Pot::Pot(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

int Pot::getSugar() {
    int sugar = analogRead(pin);
    sugar = map(sugar, 0, 1023, 1, 4);
    return sugar;
}
