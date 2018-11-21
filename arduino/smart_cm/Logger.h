#ifndef LOG_LIB
#define LOG_LIB

#include "Arduino.h"


class LoggerService {

public:

  void log(const String& msg);
};

extern LoggerService Logger;

#endif
