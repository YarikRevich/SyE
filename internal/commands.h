#include <ncurses.h>
#include <string>
#include <vector>
#include "colors.h"

using namespace std;
namespace c
{
    vector<char> _command;

    void set_command(char s)
    {
        _command.push_back(s);
    };

    string get_command()
    {
        return string(_command.data());
    };

    void reset_command()
    {
        _command.clear();
    };

    void pop_symbol_from_command()
    {
        _command.pop_back();
    };

    void apply_command(string c)
    {
        if (c == "set color blue")
        {
            set_color(BLUE);
            refresh();
        } else if (c == "w"){
            f::write_to_file();
        };
    };
};