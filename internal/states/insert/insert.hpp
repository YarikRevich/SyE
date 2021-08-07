#pragma once

namespace InsertStateStorage
{
    extern int *g_ch;
    extern bool await;
};

namespace InsertStateDefaultHandler
{
    void includeWideChar();
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

namespace InsertStateTabHandler{
    void use();
};

class InsertState
{
public:
    InsertState(int ch);

    void use();
};