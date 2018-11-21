#ifndef MSG_LIB
#define MSG_LIB

#include "Arduino.h"

class Msg {
  String content;

public:
  Msg(String content){
    this->content = content;
  }

  String getContent(){
    return content;
  }

  void setContent(String content) {
    this->content = content;
  }
};

class Pattern {
public:
  virtual boolean match(const Msg& m) = 0;
};

class MsgServiceClass {

public:

  Msg* currentMsg;
  bool msgAvailable;

  void init();

  bool isMsgAvailable();
  Msg* receiveMsg();

  bool isMsgAvailable(Pattern& pattern);
  Msg* receiveMsg(Pattern& pattern);

  void sendMsg(const String& msg);
};

extern MsgServiceClass MsgService;

#endif
