#pragma once

enum class ResizeType
{
    X,
    Y,
};

class Resizer
{
public:
    bool areMaxCoordsChanged();

    ResizeType getResizeType();

    void resizeWin();
};

extern Resizer *_WIN_RESIZER;