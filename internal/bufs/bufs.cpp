#include <type_traits>
#include <algorithm>
#include <string>
#include <math.h>
#include "./../position/position.hpp"
#include "bufs.hpp"

bool _is_insert_buf_equal_to_default()
{
    auto const insert_buf = _INSERT__BUF->get();
    auto const default_buf = _DEFAULT__BUF->get();
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
bool BufferInterface<T>::sort(T *f, T *s)
{

    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        if (f->y < s->y)
        {
            return true;
        }
        else if (f->y > s->y)
        {
            return false;
        }
        else
        {
            double g1 = sqrt(f->x * f->x + f->y * f->y);
            double g2 = sqrt(s->x * s->x + s->y * s->y);

            return g1 < g2;
        }
    }
    return false;
};

template <typename T>
bool BufferInterface<T>::is_start(int y)
{
    auto const first_cell = this->buf[0];
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        if (first_cell->y == y)
        {
            return true;
        }
    }
    return false;
};

template <typename T>
void BufferInterface<T>::set_move(int y, int x)
{
    if (this->empty)
    {
        this->empty = FALSE;
    }
    this->move = {y, x};
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
std::tuple<int, int> BufferInterface<T>::get_move()
{
    return this->move;
}

template <typename T>
void BufferInterface<T>::delete_move()
{
    this->empty = TRUE;
    this->move = {};
};

template <typename T>
bool BufferInterface<T>::is_empty()
{
    return this->empty;
}

template <typename T>
void BufferInterface<T>::pop()
{
    if (!this->buf.empty())
    {
        this->buf.pop_back();
    }
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

        // std::string e = "Buffer is: ";
        // for (int i = 0; i < e.size(); i++)
        // {
        //     _LOG__BUF.add_L(e[i], CHAR);
        // }
        // _LOG__BUF.add_L(10, CHAR);

        // for (int r = 0; r < this->buf.size(); r++)
        // {
        //     std::string u = "X is ";
        //     for (int i = 0; i < u.size(); i++)
        //     {
        //         _LOG__BUF.add_L(u[i], CHAR);
        //     }
        //     _LOG__BUF.add_L(this->buf[r]->x, INT);
        //     _LOG__BUF.add_L('\t', CHAR);

        //     u = " Y is ";
        //     for (int i = 0; i < u.size(); i++)
        //     {
        //         _LOG__BUF.add_L(u[i], CHAR);
        //     }
        //     _LOG__BUF.add_L(this->buf[r]->y, INT);
        //     _LOG__BUF.add_L(10, CHAR);
        // }

        // std::string q = std::to_string(to_emplace) + "\n";
        // for (int i = 0; i < q.size(); i++)
        // {
        //     _LOG__BUF.add_L(q[i], CHAR);
        // }

        buf_cell_C *b = new buf_cell_C;
        b->symbol = s;
        b->y = y;
        b->x = x;

        this->buf.push_back(b);

        std::sort(this->buf.begin(), this->buf.end(), this->sort);
    }
}

template <typename T>
void BufferInterface<T>::add_L(int s, L_symbol_type st)
{
    if constexpr (std::is_same_v<T, buf_cell_L>)
    {
        buf_cell_L *b = new buf_cell_L;
        b->symbol = s;
        b->type = st;
        this->buf.push_back(b);
    }
};

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
            if ((this->buf[i]->y == y) && (this->buf[i]->symbol != 10))
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
void BufferInterface<T>::translocation_up_after_y(int y)
{
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->y > y)
            {
                this->buf[i]->y++;
            }
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

template <typename T>
void BufferInterface<T>::translocation_down_after_y(int y)
{
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->y > y)
            {
                this->buf[i]->y--;
            }
        }
    }
};

template <typename T>
void BufferInterface<T>::translocation_right_after_x(int y, int x)
{
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        auto [max_y, max_x] = _POSITION.get_max_coords();
        for (int i = 0; i < this->buf.size(); i++)
        {
            if ((this->buf[i]->y >= y) && this->buf[i]->x == *max_x)
            {
                this->buf[i]->y++;
                this->buf[i]->x = 0;
            }
            else if ((this->buf[i]->y >= y) && this->buf[i]->x > x)
            {
                this->buf[i]->x++;
            }
        }
    }
};

template <typename T>
void BufferInterface<T>::translocation_left_after_x(int y, int x)
{
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        auto [max_y, max_x] = _POSITION.get_max_coords();
        for (int i = 0; i < this->buf.size(); i++)
        {
            if ((this->buf[i]->y >= y) && this->buf[i]->x == 0)
            {
                this->buf[i]->y--;
                this->buf[i]->x = *max_x;
            }
            else if ((this->buf[i]->y >= y) && this->buf[i]->x > x)
            {
                this->buf[i]->x--;
            }
        }
    }
};

template <typename T>
bool BufferInterface<T>::is_last_cell(int y, int x)
{
    if constexpr (std::is_same_v<T, buf_cell_C>)
    {
        if (!this->buf.empty())
        {
            return this->buf[this->buf.size() - 1]->y == y && this->buf[this->buf.size() - 1]->x == x;
        }
    }
    return false;
};

template <typename T>
void BufferInterface<T>::set_ignore_forcible_move(bool s)
{
    this->ignore_forcible_move = s;
};

template <typename T>
bool BufferInterface<T>::is_ignore_forcible_move()
{
    return this->ignore_forcible_move;
};

template class BufferInterface<buf_cell>;
template class BufferInterface<buf_cell_C>;
template class BufferInterface<buf_cell_L>;

BufferInterface<buf_cell_L> *_LOG__BUF = new BufferInterface<buf_cell_L>;
BufferInterface<buf_cell> *_DEFAULT__BUF = new BufferInterface<buf_cell>;
BufferInterface<buf_cell_C> *_INSERT__BUF = new BufferInterface<buf_cell_C>;
BufferInterface<buf_cell_C> *_COMMAND__BUF = new BufferInterface<buf_cell_C>;
BufferInterface<buf_cell_C> *_EFFECTS__BUF = new BufferInterface<buf_cell_C>;
BufferInterface<buf_cell_C> *_SEARCH__BUF = new BufferInterface<buf_cell_C>;
