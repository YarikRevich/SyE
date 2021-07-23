#include "editor_status.hpp"

int EditorStatus::current_status = INSERT;
int EditorStatus::checkpoint = INSERT;

void EditorStatus::setCurrStatus(int status)
{
    EditorStatus::current_status = status;
};

int EditorStatus::getCurrStatus()
{
    return EditorStatus::current_status;
};

void EditorStatus::resetCurrStatus()
{
    EditorStatus::current_status = INSERT;
};

void EditorStatus::setCheckpoint()
{
    EditorStatus::checkpoint = EditorStatus::getCurrStatus();
};

int EditorStatus::getCheckpoint()
{
    return EditorStatus::checkpoint;
}