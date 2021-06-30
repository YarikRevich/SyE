#pragma once

#include <vector>
#include <tuple>

class SearchBuf
{
private:
    std::vector<std::tuple<int, int>> search_buf;

public:
    std::vector<std::tuple<int, int>> get_buf();

    void set_buf(std::vector<std::tuple<int, int>> b);
};

extern SearchBuf _SEARCH_BUF;