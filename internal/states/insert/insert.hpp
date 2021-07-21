#include "./../../index.hpp"
#include "./../pool/pool.hpp"

class KeyHandlers
{
protected:
    int m_ch;

    int m_max_y;
    int m_max_x;

    int m_curr_y;
    int m_curr_x;

public:
    void handle_default();

    void handle_enter();

    void handle_colon();
};

class InsertState : public KeyHandlers
{

public:
    InsertState(int ch);

    void use();
};