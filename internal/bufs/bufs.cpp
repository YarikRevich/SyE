#include <type_traits>
#include "bufs.hpp"

bool _is_insert_buf_equal_to_default()
{
    auto const insert_buf = _INSERT__BUF.get();
    auto const default_buf = _DEFAULT__BUF.get();
    if ((!insert_buf.empty() && !default_buf.empty()) && (insert_buf.size() == default_buf.size()))
    {
        for (int i = 0; i < default_buf.size() - 1; i++)
        {
            if (insert_buf[i]->symbol != default_buf[i]->symbol)
            {
                return false;
            }
        }
        return true;
    }
    return false;
};

template <typename T>
bool BufferInterface<T>::is_start(int y)
{
    auto const first_cell = this->buf[0];
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        if (first_cell->y == y){
            return true;
        }
    }
    return false;
};

template <class T>
void BufferInterface<T>::erase(int y, int x)
{
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        if (this->buf.size() > 1)
        {
            for (int i = 0; i < this->buf.size(); i++)
            {

                if (this->buf[i]->x == x && this->buf[i]->y == y)
                {
                    this->buf.erase(this->buf.begin() + i);
                }
            }
        }
        else if (this->buf.size() != 0)
        {
            this->buf.erase(buf.begin());
        }
    }
}

template <typename T>
void BufferInterface<T>::pop()
{
    this->buf.erase(this->buf.end() - 1);
};

template <typename T>
void BufferInterface<T>::add_C(int s, int y, int x)
{
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {

            if (this->buf[i]->x == x && this->buf[i]->y == y)
            {
                this->erase(y, x);
            }
        }
        buf_cell_C *b = new buf_cell_C;
        b->symbol = s;
        b->y = y;
        b->x = x;
        this->buf.push_back(b);
    }
}

template <typename T>
void BufferInterface<T>::add(int s)
{
    if constexpr (std::is_same_v<T, buf_cell>)
    {
        buf_cell *b = new buf_cell;
        b->symbol = s;
        this->buf.push_back(b);
    }
}

template <typename T>
void BufferInterface<T>::set(std::vector<T *> b)
{
    this->buf = b;
};

template <typename T>
std::vector<T *> BufferInterface<T>::get()
{
    return this->buf;
};

template <typename T>
std::string BufferInterface<T>::get_as_string()
{
    std::string res;
    for (int i = 0; i < this->buf.size(); i++)
    {
        res.push_back(this->buf[i]->symbol);
    }
    return res;
};

template <typename T>
int BufferInterface<T>::get_last_x(int y)
{
    int res = 0;
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->y == y && this->buf[i]->symbol != 10)
            {
                res++;
            };
        };
    };

    return res;
};

template <typename T>
void BufferInterface<T>::set_modified(bool s)
{
    this->modified = s;
};

template <typename T>
bool BufferInterface<T>::is_modified()
{
    return this->modified;
}

template <typename T>
void BufferInterface<T>::clear()
{
    this->buf.erase(this->buf.begin(), this->buf.end());
};

template <typename T>
void BufferInterface<T>::translocation_up()
{
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            this->buf[i]->y++;
        }
    }
};

template <typename T>
void BufferInterface<T>::translocation_down()
{
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            this->buf[i]->y--;
        }
    }
};

template class BufferInterface<buf_cell>;
template class BufferInterface<buf_cell_C>;

BufferInterface<buf_cell> _LOG__BUF;
BufferInterface<buf_cell> _DEFAULT__BUF;
BufferInterface<buf_cell_C> _INSERT__BUF;
BufferInterface<buf_cell_C> _COMMAND__BUF;
BufferInterface<buf_cell_C> _EFFECTS__BUF;
BufferInterface<buf_cell_C> _SEARCH__BUF;
