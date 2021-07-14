#include <math.h>
#include "bufs.hpp"
#include <iostream>
#include <algorithm>
#include <type_traits>
#include "./../colors/colors.hpp"
#include "./../position/position.hpp"

bool isInsertSameToDefaultBuf()
{
    auto const insert_buf = _INSERT__BUF->getBuf();
    auto const default_buf = _DEFAULT__BUF->getBuf();
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
void CoordsTranslocation<T>::translocateYUp()
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            this->buf[i]->y++;
        }
    }
};

template <typename T>
void CoordsTranslocation<T>::translocateYUpAfter(int y)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
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
void CoordsTranslocation<T>::translocateYDown()
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->y != 0)
            {
                this->buf[i]->y--;
            }
        }
    }
};

template <typename T>
void CoordsTranslocation<T>::translocateYDownAfter(int y)
{

    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        // std::string s = "Buffer before : ";
        // for (auto const i : s)
        // {
        //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
        // }
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // for (auto const i : this->getBuf())
        // {
        //     s = "Y is ";
        //     for (auto const b : s)
        //     {
        //         _LOG__BUF->addCellWithSymbolType(b, CHAR);
        //     }
        //     _LOG__BUF->addCellWithSymbolType(i->y, INT);
        //     s = " ,X is ";
        //     for (auto const b : s)
        //     {
        //         _LOG__BUF->addCellWithSymbolType(b, CHAR);
        //     }
        //     _LOG__BUF->addCellWithSymbolType(i->x, INT);
        //     _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // }
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);

        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->y > y && !this->isStartRow(this->buf[i]->y))
            {
                this->buf[i]->y--;
            }
        }

        // s = "Buffer after : ";
        // for (auto const i : s)
        // {
        //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
        // }
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // for (auto const i : this->getBuf())
        // {
        //     s = "Y is ";
        //     for (auto const b : s)
        //     {
        //         _LOG__BUF->addCellWithSymbolType(b, CHAR);
        //     }
        //     _LOG__BUF->addCellWithSymbolType(i->y, INT);
        //     s = " ,X is ";
        //     for (auto const b : s)
        //     {
        //         _LOG__BUF->addCellWithSymbolType(b, CHAR);
        //     }
        //     _LOG__BUF->addCellWithSymbolType(i->x, INT);
        //     _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // }
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
    }
};

template <typename T>
void CoordsTranslocation<T>::translocateXRightAfter(int y, int x)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
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
void CoordsTranslocation<T>::translocateXLeftAfter(int y, int x)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        std::string s = "Buffer before : ";
        for (auto const i : s)
        {
            _LOG__BUF->addCellWithSymbolType(i, CHAR);
        }
        _LOG__BUF->addCellWithSymbolType(10, CHAR);
        for (auto const i : this->getBuf())
        {
            s = "Y is ";
            for (auto const b : s)
            {
                _LOG__BUF->addCellWithSymbolType(b, CHAR);
            }
            _LOG__BUF->addCellWithSymbolType(i->y, INT);
            s = " ,X is ";
            for (auto const b : s)
            {
                _LOG__BUF->addCellWithSymbolType(b, CHAR);
            }
            _LOG__BUF->addCellWithSymbolType(i->x, INT);
            _LOG__BUF->addCellWithSymbolType(10, CHAR);
        }
        _LOG__BUF->addCellWithSymbolType(10, CHAR);

        auto [max_y, max_x] = _POSITION.get_max_coords();
        for (int i = 0; i < this->buf.size(); i++)
        {
            if ((this->buf[i]->y >= y) && (this->buf[i]->x >= x) && (this->buf[i]->symbol == 10))
            {
                break;
            }
            else if ((this->buf[i]->y > y) && (this->buf[i]->x == 0))
            {
                this->buf[i]->y--;
                this->buf[i]->x = *max_x;
            }
            else if ((this->buf[i]->y >= y) && this->buf[i]->x >= x)
            {
                this->buf[i]->x--;
            }
        }

        s = "Buffer after : ";
        for (auto const i : s)
        {
            _LOG__BUF->addCellWithSymbolType(i, CHAR);
        }
        _LOG__BUF->addCellWithSymbolType(10, CHAR);
        for (auto const i : this->getBuf())
        {
            s = "Y is ";
            for (auto const b : s)
            {
                _LOG__BUF->addCellWithSymbolType(b, CHAR);
            }
            _LOG__BUF->addCellWithSymbolType(i->y, INT);
            s = " ,X is ";
            for (auto const b : s)
            {
                _LOG__BUF->addCellWithSymbolType(b, CHAR);
            }
            _LOG__BUF->addCellWithSymbolType(i->x, INT);
            _LOG__BUF->addCellWithSymbolType(10, CHAR);
        }
        _LOG__BUF->addCellWithSymbolType(10, CHAR);
    }
};

void Movement::setMovement(int y, int x)
{
    if (this->empty)
    {
        this->empty = FALSE;
    }
    this->movement = {y, x};
};

std::tuple<int, int> Movement::getMovement()
{
    return this->movement;
}

void Movement::deleteMovement()
{
    this->empty = TRUE;
    this->movement = {};
};

bool Movement::isEmpty()
{
    return this->empty;
}

void Movement::setIgnoreForcibleMove(bool s)
{
    this->ignoreForcibleMove = s;
};

bool Movement::isIgnoreForcibleMove()
{
    return this->ignoreForcibleMove;
};

void Movement::resetIgnoreForcibleMove()
{
    this->ignoreForcibleMove = false;
};

template <typename T>
bool Base<T>::sort(T *currentBufferCell, T *nextBufferCell)
{

    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        if (currentBufferCell->y < nextBufferCell->y)
        {
            return true;
        }
        else if (currentBufferCell->y > nextBufferCell->y)
        {
            return false;
        }
        else
        {
            double g1 = sqrt(currentBufferCell->x * currentBufferCell->x + currentBufferCell->y * currentBufferCell->y);
            double g2 = sqrt(nextBufferCell->x * nextBufferCell->x + nextBufferCell->y * nextBufferCell->y);

            return g1 < g2;
        }
    }
    return false;
};

template <typename T>
void Base<T>::createID()
{
    this->id = rand();
};

template <typename T>
int Base<T>::getID()
{
    return this->id;
};

template <typename T>
bool Base<T>::isStartRow(int y)
{
    auto const first_cell = this->buf[0];
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        if (first_cell->y == y)
        {
            return true;
        }
    }
    return false;
};

template <class T>
void Base<T>::eraseCell(int y, int x)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
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
void Base<T>::addCellWithCoords(int s, int y, int x)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->x == x && this->buf[i]->y == y)
            {
                this->eraseCell(y, x);
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

        BufferCellWithCoords *b = new BufferCellWithCoords;
        b->symbol = s;
        b->y = y;
        b->x = x;
        b->sentenceHyphenation = false;

        this->buf.push_back(b);

        std::sort(this->buf.begin(), this->buf.end(), this->sort);
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    }
}

template <typename T>
void Base<T>::addCellWithSymbolType(int s, SymbolType st)
{
    if constexpr (std::is_same_v<T, BufferCellWithSymbolType>)
    {
        BufferCellWithSymbolType *b = new BufferCellWithSymbolType;
        b->symbol = s;
        b->type = st;
        this->buf.push_back(b);
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    }
};

template <typename T>
void Base<T>::addCell(int s)
{
    if constexpr (std::is_same_v<T, BufferCell>)
    {
        BufferCell *b = new BufferCell;
        b->symbol = s;
        this->buf.push_back(b);
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    }
}

template <typename T>
std::vector<T *> Base<T>::getBuf()
{
    return this->buf;
};

template <typename T>
void Base<T>::setCellWithCoordsColor(int y, int x, std::string color)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        auto buf = this->getBuf();
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i]->y == y && buf[i]->x == x)
            {
                buf[i]->fontColor = color;
            };
        };
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    }
};

template <typename T>
void Base<T>::setCellSentenceHyphenation(int y, int x, bool status)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->y == y && this->buf[i]->x == x)
            {
                this->buf[i]->sentenceHyphenation = status;
            }
        }
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    }
};

template <typename T>
bool Base<T>::cellIsSentenceHyphenation(int y, int x)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->y == y && this->buf[i]->x == x)
            {
                return this->buf[i]->sentenceHyphenation;
            }
        }
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    }
    return false;
}

template <typename T>
std::tuple<int, int> Base<T>::getEndOfSentence(int y, int x)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->y >= y && !this->cellIsSentenceHyphenation(this->buf[i]->y, this->getLastXInRow(this->buf[i]->y)))
            {
                return {this->buf[i]->y, this->buf[i]->x};
            };
        }
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    }
    return {0, 0};
};

template <typename T>
std::vector<BufferCellWithCoords *> Base<T>::getRowWithY(int y)
{
    std::vector<BufferCellWithCoords *> res;
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        std::vector<BufferCellWithCoords *> buf = this->getBuf();
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i]->y == y)
            {
                res.push_back(buf[i]);
            }
        };
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    }
    return res;
};

template <typename T>
std::string Base<T>::getBufAsString()
{
    std::string res;
    for (auto cell : this->getBuf())
    {
        res += cell->symbol;
    };
    return res;
};

template <typename T>
std::vector<BufferAsString> Base<T>::getBufAsStringWithYCoord()
{
    std::vector<BufferAsString> res;

    int y = 0;
    while (1)
    {
        std::vector<BufferCellWithCoords *> row = this->getRowWithY(y);
        if (row.empty())
        {
            break;
        }

        BufferAsString rowAsString;
        rowAsString.y = y;
        for (auto cell : row)
        {
            rowAsString.text += cell->symbol;
        };
        res.push_back(rowAsString);
        y++;
    }
    return res;
};

template <typename T>
int Base<T>::getLastXInRow(int y)
{
    int res = 0;
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if ((this->buf[i]->y == y) && (this->buf[i]->symbol != 10))
            {
                res++;
            };
        };
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    };

    return res;
};

void Status::setModified(bool s)
{
    this->modified = s;
};

bool Status::isModified()
{
    return this->modified;
}

template <typename T>
void Base<T>::clearBuf()
{
    this->buf.erase(this->buf.begin(), this->buf.end());
};

template <typename T>
bool Base<T>::isLastBufCell(int y, int x)
{
    if constexpr (std::is_same_v<T, BufferCellWithCoords>)
    {
        if (!this->buf.empty())
        {
            return this->buf[this->buf.size() - 1]->y == y && this->buf[this->buf.size() - 1]->x == x;
        }
    }
    else
    {
        throw std::logic_error("This method can't be used with buf which cells don't have coords");
    }
    return false;
};

template <typename T>
Buffer<T>::Buffer()
{
    this->createID();
};

template class Buffer<BufferCell>;
template class Buffer<BufferCellWithCoords>;
template class Buffer<BufferCellWithSymbolType>;

template class Base<BufferCell>;
template class Base<BufferCellWithCoords>;
template class Base<BufferCellWithSymbolType>;

template class CoordsTranslocation<BufferCell>;
template class CoordsTranslocation<BufferCellWithCoords>;
template class CoordsTranslocation<BufferCellWithSymbolType>;

Buffer<BufferCellWithSymbolType> *_LOG__BUF = new Buffer<BufferCellWithSymbolType>;
Buffer<BufferCell> *_DEFAULT__BUF = new Buffer<BufferCell>;
Buffer<BufferCellWithCoords> *_INSERT__BUF = new Buffer<BufferCellWithCoords>;
Buffer<BufferCellWithCoords> *_COMMAND__BUF = new Buffer<BufferCellWithCoords>;
Buffer<BufferCellWithCoords> *_EFFECTS__BUF = new Buffer<BufferCellWithCoords>;
Buffer<BufferCellWithCoords> *_SEARCH__BUF = new Buffer<BufferCellWithCoords>;
