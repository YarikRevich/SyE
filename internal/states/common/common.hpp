namespace CommonStateStorage
{
    extern int *g_ch;
};

namespace CommonStateUpHandler
{
    void use();
};

namespace CommonStateDownHandler
{
    void use();
};

namespace CommonStateLeftHandler
{
    void use();
};

namespace CommonStateRightHandler
{
    void use();
};

namespace CommonStateBackspaceHandler
{
    void use();
};

class CommonState
{
public:
    CommonState(int ch);

    void use();
};
