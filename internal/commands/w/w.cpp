#include "w.hpp"
#include "./../../files/exec/exec.hpp"

void W_Command::execute()
{
   _EXEC_FILE->save();
}