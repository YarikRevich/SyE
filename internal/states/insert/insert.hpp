#pragma once

namespace InsertStateStorage
{
    extern int *g_ch;
};

namespace InsertStateDefaultHandler
{
    void moveCariage();
    void use();
};

namespace InsertStateEnterHandler
{
    void moveCariage();
    void includeWordAreaOffsetDown();
    void use();
};

namespace InsertStateColonHandler
{
    void fillPanelWithSpaces();
    void modifyBuffer();
    void modifyState();
    void use();
};

class InsertState
{
public:
    InsertState(int ch);

    void use();
};