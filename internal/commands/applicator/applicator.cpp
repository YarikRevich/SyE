#include "applicator.hpp"
#include "./../w/w.hpp"
#include "./../search/search.hpp"

#include "./../../editor_status/editor_status.hpp"

void Applicator::apply_command(std::string c)
{
    std::transform(c.begin(), c.end(), c.begin(), [](char t)
                   { return tolower(t); });

    if (c == "w")
    {
        W_Command().execute();
    }
    else if (c[0] == '/')
    {
        Search_Command().execute();
    }
};