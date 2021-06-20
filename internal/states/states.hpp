#include <map>
#include "./../commands/commands.hpp"

#define INSERT 0
#define COMMAND 1

//Common handlers ids

#define BACKSPACE 2

namespace sm
{
    extern int _CURR_STATE;

    void set_state(int state);

    void reset_state();

    int get_state();
};

namespace hnd
{
    extern std::map<int, bool> handler_status;

    void set_handled_status(int id, bool status);

    bool get_handled_status(int id);

    void reset_handled_status();

    //Contains all the handlers
    class Handler
    {
    public:
        virtual void handle(int ch) = 0;
    };

    class CommonHandler : public Handler
    {
    public:
        virtual void handle(int ch);
    };

    class InsertHandler : public Handler
    {
    public:
        virtual void handle(int ch);
    };

    class CommandHandler : public Handler
    {
    public:
        virtual void handle(int ch);
    };

    class HandlerPool
    {
    public:
        void handle(Handler *h, int ch);
    };
};