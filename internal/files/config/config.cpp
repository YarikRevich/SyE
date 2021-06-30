#include "config.hpp"
#include <stdio.h>
#include <iostream>

void Config::read()
{

    if (fopen("~/.sye_config", "r"))
    {
    }
    else
    {
        this->file = fopen("~/.sye_config", "w");
        
    };
};
void Config::save(){

};
void Config::set_color(int c){

};