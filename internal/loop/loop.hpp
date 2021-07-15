#pragma once

class Stages
{
protected:
    void prepare_run();
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