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

namespace Stages
{

    namespace Initialisers
    {
        void init_insert_buf();
        void init_configs();
        void init_term_flags();
        void init_ncurses();
        void init_colors();
        void init_signals();
    };

    namespace LoopParts
    {
        void process_states();
        namespace Render
        {
            void do_before_render();
            void render();
            void do_after_render();
        };
        void reset_temporary_data();
    };
}

namespace Loop
{
    void run();
};
