#pragma once

namespace SearchStateStorage
{
    extern int *g_ch;
};

namespace SearchStateUpHandler
{
    void use();
};

namespace SearchStateDownHandler
{
    void use();
};

namespace SearchStateLeftHandler
{
    void use();
};

namespace SearchStateRightHandler
{
    void use();
};

namespace SearchStateEnterHandler
{
    void use();
};

class SearchState
{
public:
    SearchState(int ch);

    void use();
};