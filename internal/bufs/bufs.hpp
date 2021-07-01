#pragma once

#include "./../index.hpp"

//Shows if insert buf is the same to default one
bool _is_insert_buf_equal_to_default();

extern BufferInterface<buf_cell> _LOG__BUF;
extern BufferInterface<buf_cell> _DEFAULT__BUF;
extern BufferInterface<buf_cell_C> _INSERT__BUF;
extern BufferInterface<buf_cell_C> _COMMAND__BUF;
extern BufferInterface<buf_cell_C> _EFFECTS__BUF;
extern BufferInterface<buf_cell_C> _SEARCH__BUF;