#include "search_buf.hpp"

std::vector<std::tuple<int, int>> SearchBuf::get_buf()
{
    return search_buf;
};

void SearchBuf::set_buf(std::vector<std::tuple<int, int>> b)
{
    search_buf = b;
};

SearchBuf _SEARCH_BUF;