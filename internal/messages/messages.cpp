#include "messages.hpp"


Message::Message(void * message){
    this->message = message;
};
void *Message::get(){
    return this->message;
};

class MessageWriter
{
public:
    MessageWriter(std::vector<Message>);
};
