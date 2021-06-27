#include <map>
#include "./../pool/pool.hpp"

extern std::map<int, bool> handler_status;

void set_handled_status(int id);

bool is_handled(int id);

void reset_handled_status();

bool is_handler(int ch);

class CommonHandler : public Handler
{
public:
    void handle(int ch);
};
