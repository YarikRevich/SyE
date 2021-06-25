#include <map>
#include "./../pool/pool.hpp"

#define BACKSPACE 2

extern std::map<int, bool> handler_status;

void set_handled_status(int id, bool status);

bool is_handled(int id);

void reset_handled_status();

class CommonHandler : public Handler
{
public:
    void handle(int ch);
};
