namespace CommonStateStorage
{
    extern int *g_ch;
};

namespace CommonStateUpHandler
{
    void includeWordAreaOffsetUp();
    void moveLineUp();
    void use();
};

namespace CommonStateDownHandler
{
    void includeWordAreaOffsetDown();
    void moveLineDown();
    void use();
};

namespace CommonStateLeftHandler
{
    void moveRowLeft();
    void use();
};

namespace CommonStateRightHandler
{
    void use();
};

namespace CommonStateBackspaceHandler
{
    void moveRowUp();
    void moveBufferUp();
    void shiftRowToLeft();
    void use();
};

class CommonState
{
public:
    CommonState(int ch);

    void use();
};
