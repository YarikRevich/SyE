#include "pool.hpp"


void HandlerPool::handle(HandlerInterface *h, int ch)
{
    h->handle(ch);
};
