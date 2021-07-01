#include <map>
#include "./../../index.hpp"
#include "./../pool/pool.hpp"

extern std::map<int, bool> handler_status;

void set_handled_status(int id);

bool is_common_handled(int id);

void reset_handled_status();

bool is_common_handler(int ch);

class CommonHandler : public HandlerInterface
{
public:
    void handle(int ch);
};
