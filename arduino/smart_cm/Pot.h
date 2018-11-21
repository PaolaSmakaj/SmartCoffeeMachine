#ifndef POT_LIB
#define POT_LIB

class Pot {
private:
    int pin;

public:
    Pot(int pin);
    int getSugar();    
};

#endif
