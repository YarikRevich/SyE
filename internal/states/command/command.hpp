#pragma once

namespace CommandStateStorage
{
    extern int *g_ch;
};

namespace CommandStateDefaultHandler
{
    void use();
};

namespace CommandStateEnterHandler
{
    void cleanBuffers();
    void modifyState();
    void use();
};

namespace CommandStateBackspaceHandler
{
    void cleanBuffers();
    void modifyCurrentlyProcessedBuffer();
    void use();
};

class CommandState
{
public:
    CommandState(int ch);

    void use();
};
