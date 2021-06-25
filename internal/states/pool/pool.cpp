#include "pool.hpp"

void HandlerPool::handle(Handler *h, int ch)
{
    h->handle(ch);
};
