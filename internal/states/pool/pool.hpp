#pragma once

class Handler
{
public:
    virtual void handle(int ch) = 0;
};

class HandlerPool
{
public:
    void handle(Handler *h, int ch);
};