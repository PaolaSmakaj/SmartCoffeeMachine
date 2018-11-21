#include "CoffeeCommTask.h"
#include "pinconfig.h"
#include "Logger.h"

#define MSG_COFFEE_REFILLED "5"

extern bool refilled;

CoffeeCommTask::CoffeeCommTask(){

}

void CoffeeCommTask::init(int period){
  Task::init(period);
}

void CoffeeCommTask::tick(){
  if (MsgService.isMsgAvailable()){
    Msg* msg = MsgService.receiveMsg();
    const String& content = msg->getContent();
    if (content == MSG_COFFEE_REFILLED){
      msg->setContent("COFFEE REFILLED");
      Logger.log("Coffee refilled: 3");
      refilled = true;
    } else {
      Logger.log("CCT: unknown req: "+content);
    }

    
  delete msg;
  }
}
