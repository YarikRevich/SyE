
#include "init.hpp"
#include <ncurses.h>

Init::Init()
{
   
};

void Init::End(){
    //Disables ncurses mode in terminal
    endwin();
};