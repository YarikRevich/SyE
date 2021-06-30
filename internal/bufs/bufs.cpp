#include "bufs.hpp"

bool _is_insert_buf_equal_to_default()
{
    auto const insert_buf = _INSERT__BUF.get();
    auto const default_buf = _DEFAULT__BUF.get();
    if ((!insert_buf.empty() && !default_buf.empty()) && (insert_buf.size() == default_buf.size()))
    {
        for (int i = 0; i < default_buf.size() - 1; i++)
        {
            if (insert_buf[i].symbol != default_buf[i].symbol)
            {
                return false;
            }
        }
        return true;
    }
    return false;
};

template <class T>
void BufferInterface<T>::erase(int y, int x)
{
    if (this->buf.size() > 1)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i].x == x && this->buf[i].y == y)
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

template <class T>
void BufferInterface<T>::add_C(int s, int y, int x)
{
    for (int i = 0; i < this->buf.size(); i++)
    {
        if (this->buf[i].x == x && this->buf[i].y == y)
        {
            this->erase(y, x);
        }
    }
    this->buf.push_back({s, y, x});
}

template <class T>
void BufferInterface<T>::add(int s)
{
    this->buf.push_back({s});
}

template <class T>
void BufferInterface<T>::set(std::vector<T> b)
{
    this->buf = b;
};

template <class T>
std::vector<T> BufferInterface<T>::get()
{
    return this->buf;
};

template <class T>
void BufferInterface<T>::set_modified(bool s)
{
    this->modified = s;
};

template <class T>
bool BufferInterface<T>::is_modified()
{
    return this->modified;
}

BufferInterface<buf_cell> _LOG__BUF;
BufferInterface<buf_cell> _DEFAULT__BUF;
BufferInterface<buf_cell_C> _INSERT__BUF;
BufferInterface<buf_cell_C> _COMMAND__BUF;
BufferInterface<buf_cell_C> _SEARCH__BUF;
