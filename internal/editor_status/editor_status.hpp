#pragma once

#define INSERT 0
#define COMMAND 1
#define SEARCH 2

namespace EditorStatus
{
    extern int current_status, checkpoint;

    void setCurrStatus(int status);

    int getCurrStatus();

    void resetCurrStatus();

    void setCheckpoint();

    int getCheckpoint();
};
