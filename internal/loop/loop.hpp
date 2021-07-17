#pragma once

#include <functional>

class Middleware
{
private:
    std::function<void()> middleware;

public:
    Middleware(std::function<void()> middleware);
    void use();
};

class MiddlwareExecutor
{
public:
    MiddlwareExecutor(std::vector<Middleware>);
};

class Stages
{
protected:
    void init_insert_buf();
    void init_configs();

    void prepare_configs();
    void handle_updation();
    void prepare_for_render();
    void render();
    void post_render();
    void reset_temporary_data();
};

class Loop : public Stages
{
private:
public:
    void run();
};

extern Loop *_LOOP;