#include "./../../../../file/file.hpp"
#include "w.hpp"

void W_Command::execute()
{
    _FILE.save();
}