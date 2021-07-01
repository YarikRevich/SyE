#pragma once

#include "./../../index.hpp"

class HandlerPool
{
public:
    void handle(HandlerInterface *h, int ch);
};