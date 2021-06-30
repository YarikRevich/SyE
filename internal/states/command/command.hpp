#include "./../../index.hpp"
#include "./../pool/pool.hpp"

class CommandHandler : public HandlerInterface
{
public:
    virtual void handle(int ch);
};
