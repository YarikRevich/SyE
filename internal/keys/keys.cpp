#include <cstring>
#include <string>
#include <ncurses.h>

#include <tuple>
#include <vector>

std::tuple<std::vector<char>, bool> ctrl(int ch)
{
    std::string const s = std::string(keyname(ch));
    if (s.size() > 1)
    {
        if (s[0] == 94)
        {
            std::vector<char> t;
            for (int i = 0; i < s.size(); i++)
            {
                t.push_back(s[i]);
            }
            return {t, true};
        }
    }
    return {{}, false};
};