#include <map>

#define INSERT 0
#define COMMAND 1

//Common handlers ids

#define BACKSPACE 2

namespace sm
{
    int _CURR_STATE = INSERT;

    void set_state(int state);

    void reset_state();

    int get_state();
};

namespace hnd
{
    std::map<int, bool> handler_status;

    void set_handled_status(int id, bool status);

    bool get_handled_status(int id);

    //Contains all the handlers
    class Handler
    {
        //Interface for handlers

    public:
        virtual void handle(int ch);
    };

    class CommonHandler : public Handler
    {
    public:
        void handle(int ch);
    };

    class InsertHandler : public Handler
    {
    public:
        void handle(int ch);
    };

    class CommandHandler : public Handler
    {
    public:
        void handle(int ch);
    };

    class HandlerPool
    {
    public:
        void handle(Handler h, int ch);
    };
};