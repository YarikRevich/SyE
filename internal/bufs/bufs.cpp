#include <math.h>
#include "bufs.hpp"
#include <iostream>
#include <algorithm>
#include <type_traits>
#include "./../colors/colors.hpp"
#include "./../position/position.hpp"
#include "./../../tools/template_assertion/template_assertion.hpp"

bool isInsertSameToDefaultBuf()
{
    auto const insert_buf = _INSERT__BUF->getBufferIterator();
    auto const default_buf = _DEFAULT__BUF->getBufferIterator();
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
void CoordsTranslocation<T>::translocateYUp() const
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            this->buf[i]->coords.y++;
        }
    }
};

template <typename T>
void CoordsTranslocation<T>::translocateYUpAfter(int y)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        for (int i = 0; i < this->buf.size(); i++)
        {

            if (this->buf[i]->coords.y > y)
            {
                this->buf[i]->coords.y++;
            }
        }
    }
};

template <typename T>
void CoordsTranslocation<T>::translocateYDown()
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->coords.y != 0)
            {
                this->buf[i]->coords.y--;
            }
        }
    }
};

template <typename T>
void CoordsTranslocation<T>::translocateYDownAfter(int y)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        for (int i = 0; i < this->buf.size(); ++i)
        {
            if (this->buf[i]->coords.y > y && !this->isStartRow(this->buf[i]->coords.y))
            {
                this->buf[i]->coords.y--;
            }
        }
    }
};

template <typename T>
void CoordsTranslocation<T>::translocateXRightAfter(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {

        _LOG__BUF->addCellWithSymbolType(10, CHAR);
        for (int i = 0; i < this->buf.size(); i++)
        {

            if ((this->buf[i]->coords.y >= y) && this->buf[i]->coords.x == Coords::max_x)
            {
                this->buf[i]->coords.y++;
                this->buf[i]->coords.x = 0;
            }
            else if ((this->buf[i]->coords.y >= y) && this->buf[i]->coords.x >= x)
            {

                _LOG__BUF->addCellWithSymbolType(10, CHAR);
                _LOG__BUF->addCellWithSymbolType(this->buf[i]->symbol, INT);
                _LOG__BUF->addCellWithSymbolType(' ', CHAR);
                _LOG__BUF->addCellWithSymbolType((this->buf[i]->coords.y >= y) && this->buf[i]->coords.x >= x, INT);
                if (this->buf[i]->symbol != ' ')
                {
                    // _LOG__BUF->addCellWithSymbolType(10, CHAR);
                    // _LOG__BUF->addCellWithSymbolType(this->buf[i]->symbol, INT);
                    if (i != 0 && (this->buf[i - 1]->coords.x >= x &&
                                   this->buf[i - 1]->coords.y >= y))
                    {
                        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
                        // _LOG__BUF->addCellWithSymbolType('O', CHAR);
                        // this->buf[i - 1]->coords.x++;
                    }

                    if (i != this->buf.size() - 1 && (this->buf[i + 1]->coords.x >= x &&
                                                      this->buf[i + 1]->coords.y >= y))
                    {
                        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
                        // _LOG__BUF->addCellWithSymbolType('B', CHAR);
                        // this->buf[i + 1]->coords.x++;
                    }
                }
                // this->buf[i]->coords.x++;
            }
        }
    }
};

template <typename T>
void CoordsTranslocation<T>::translocateXLeftAfter(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {

        // std::string s = "Buffer before : ";
        // for (auto const i : s)
        // {
        //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
        // }
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // for (auto const i : this->getBufferIterator())
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
            if ((this->buf[i]->coords.y >= y) && (this->buf[i]->coords.x >= x) && (this->buf[i]->symbol == 10))
            {
                break;
            }
            else if ((this->buf[i]->coords.y > y) && (this->buf[i]->coords.x == 0))
            {
                this->buf[i]->coords.y--;
                this->buf[i]->coords.x = Coords::max_x;
            }
            else if ((this->buf[i]->coords.y >= y) && this->buf[i]->coords.x >= x)
            {
                this->buf[i]->coords.x--;
            }
        }
    };

    // s = "Buffer after : ";
    // for (auto const i : s)
    // {
    //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
    // }
    // _LOG__BUF->addCellWithSymbolType(10, CHAR);
    // for (auto const i : this->getBufferIterator())
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
};

template <typename T>
bool Base<T>::sort(T *nextBufferCell, T *currentBufferCell)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {

        // if ((currentBufferCell->coords.y == nextBufferCell->coords.y) &&
        //     (currentBufferCell->coords.x == nextBufferCell->coords.x))
        // {
        //     return true;
        // }
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // for (auto i : std::string("   NEW !!!!"))
        // {
        //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
        // };
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // for (auto i : std::string("CURRENT"))
        // {
        //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
        // };
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // _LOG__BUF->addCellWithSymbolType(currentBufferCell->coords.y, INT);
        // _LOG__BUF->addCellWithSymbolType(' ', CHAR);
        // _LOG__BUF->addCellWithSymbolType(currentBufferCell->coords.x, INT);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // for (auto i : std::string("NEXT"))
        // {
        //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
        // };
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // _LOG__BUF->addCellWithSymbolType(nextBufferCell->coords.y, INT);
        // _LOG__BUF->addCellWithSymbolType(' ', CHAR);
        // _LOG__BUF->addCellWithSymbolType(nextBufferCell->coords.x, INT);

        if (currentBufferCell->coords.y < nextBufferCell->coords.y)
        {
            return false;
        }
        else if (currentBufferCell->coords.y > nextBufferCell->coords.y)
        {
            return true;
        }
        // else if (currentBufferCell->coords.y == nextBufferCell->coords.y &&
        //          currentBufferCell->coords.x == nextBufferCell->coords.x)
        // {
        //     return true;
        // }
        else
        {
            double g1 = sqrt(currentBufferCell->coords.x * currentBufferCell->coords.x + currentBufferCell->coords.y * currentBufferCell->coords.y);
            double g2 = sqrt(nextBufferCell->coords.x * nextBufferCell->coords.x + nextBufferCell->coords.y * nextBufferCell->coords.y);

            return g1 > g2;
        };
    };
    return false;
};

template <typename T>
bool Base<T>::isStartRow(int y)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto const first_cell = this->buf[0];

        if (first_cell->coords.y == y)
        {
            return true;
        };
    };
    return false;
};

template <typename T>
BufferCellOnlyWithCoords *Base<T>::getPrevCellByCoords(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellOnlyWithCoords))
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->coords.y == y && this->buf[i]->coords.x == x)
            {
                return i == 0 ? this->buf[i] : this->buf[i - 1];
            };
        };
    };
    return nullptr;
};

template <typename T>
BufferCellOnlyWithCoords *Base<T>::getNextCellByCoords(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellOnlyWithCoords))
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->coords.y == y && this->buf[i]->coords.x == x)
            {
                return i == this->buf.size() - 1 ? this->buf[i] : this->buf[i + 1];
            };
        };
    };
    return nullptr;
};

template <class T>
void Base<T>::eraseCell(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        if (this->buf.size() > 1)
        {
            int index_of_cell_to_delete = 0;
            for (int i = 0; i < this->buf.size(); i++)
            {
                if (this->buf[i]->coords.x == x && this->buf[i]->coords.y == y)
                {
                    index_of_cell_to_delete = i;
                }
            }
            if (index_of_cell_to_delete != 0)
            {
                this->buf.erase(this->buf.begin() + index_of_cell_to_delete);

                if (this->buf[index_of_cell_to_delete - 1]->coords.y == y && this->buf[index_of_cell_to_delete - 1]->coords.x == x)
                {
                    this->buf.erase(this->buf.begin() + index_of_cell_to_delete - 1);
                }
            }
        }
        else if (this->buf.size() != 0)
        {
            this->buf.erase(buf.begin());
        };
    };
}

template <typename T>
void Base<T>::addCellWithCoords(int s, int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        BufferCellWithCoords *b = new BufferCellWithCoords;
        b->symbol = s;
        b->coords.y = y;
        b->coords.x = x;
        b->sentenceHyphenation = false;

        this->buf.push_back(b);

        // std::sort(this->buf.begin(), this->buf.end(), this->sort);
    };
}

template <typename T>
void Base<T>::addCellWithSymbolType(int s, SymbolType st)
{
    if constexpr (buffer_assertion(T, BufferCellWithSymbolType))
    {
        BufferCellWithSymbolType *b = new BufferCellWithSymbolType;
        b->symbol = s;
        b->type = st;
        this->buf.push_back(b);
    };
};

template <typename T>
void Base<T>::addCellOnlyWithSymbol(int s)
{
    if constexpr (buffer_assertion(T, BufferCellOnlyWithSymbol))
    {
        BufferCellOnlyWithSymbol *b = new BufferCellOnlyWithSymbol;
        b->symbol = s;
        this->buf.push_back(b);
    };
}

template <typename T>
void Base<T>::addCellOnlyWithCoords(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellOnlyWithCoords))
    {
        BufferCellOnlyWithCoords *b = new BufferCellOnlyWithCoords;
        b->coords.y = y;
        b->coords.x = x;
        this->buf.push_back(b);
    };
};

template <typename T>
void Base<T>::addCellToEnd(int s)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        std::vector<T *> const buf = this->getBufferIterator();

        T *const last_cell = buf[buf.size() - 1];

        T *b = new T;
        if (last_cell->coords.x == Coords::max_x)
        {
            b->coords.y = (last_cell->coords.y + 1);
            b->coords.x = 0;
        }
        else
        {
            b->coords.x = (last_cell->coords.x + 1);
        }
        b->symbol = s;
        this->buf.push_back(b);
    };
};

template <typename T>
void Base<T>::addEolIfNotExists()
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        if (this->buf.begin() != this->buf.end())
        {
            std::vector<T *> const buf = this->getBufferIterator();
            if (buf[buf.size() - 1]->symbol != 10)
            {
                T *b = new T;
                b->symbol = 10;
                this->buf.push_back(b);
            }
        };
    };
};

template <typename T>
std::vector<T *> &Base<T>::getBufferIterator()
{
    return this->buf;
};

template <typename T>
void Base<T>::setCellWithCoordsColor(int y, int x, std::string color)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto buf = this->getBufferIterator();
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i]->coords.y == y && buf[i]->coords.x == x)
            {
                buf[i]->fontColor = color;
            };
        };
    };
};

template <typename T>
void Base<T>::setCellSentenceHyphenation(int y, int x, bool status)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->coords.y == y && this->buf[i]->coords.x == x)
            {
                this->buf[i]->sentenceHyphenation = status;
            };
        };
    };
};

template <typename T>
bool Base<T>::cellIsSentenceHyphenation(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->coords.y == y && this->buf[i]->coords.x == x)
            {
                return this->buf[i]->sentenceHyphenation;
            };
        };
    };
    return false;
}

template <typename T>
std::tuple<int, int> Base<T>::getEndOfSentence(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        for (int i = 0; i < this->buf.size(); i++)
        {
            if (this->buf[i]->coords.y >= y && !this->cellIsSentenceHyphenation(this->buf[i]->coords.y, this->getLastXInRow(this->buf[i]->coords.y)))
            {
                return {this->buf[i]->coords.y, this->buf[i]->coords.x};
            };
        };
    };
    return {0, 0};
};

template <typename T>
std::vector<BufferCellWithCoords *> Base<T>::getRowWithY(int y)
{
    std::vector<BufferCellWithCoords *> res;
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        std::vector<BufferCellWithCoords *> buf = this->getBufferIterator();
        for (int i = 0; i < buf.size(); ++i)
        {
            if (buf[i]->coords.y == y)
            {
                res.push_back(buf[i]);
            };
        };
    };
    return res;
};

template <typename T>
std::string Base<T>::getBufAsString()
{
    std::string res;
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        for (auto cell : this->getBufferIterator())
        {
            res += cell->symbol;
        };
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
        ++y;
    }
    return res;
};

template <typename T>
int Base<T>::getLastXInRow(int y)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        int chars = 0;
        int wideChars = 0;
        for (int i = 0; i < this->buf.size(); i++)
        {
            if ((this->buf[i]->coords.y == y) && (this->buf[i]->symbol != 10))
            {
                if (i != 0)
                {
                    if (this->buf[i - 1]->coords.y == y && this->buf[i - 1]->coords.x == this->buf[i]->coords.x)
                    {
                        wideChars += 2;
                    };
                };
                chars++;
            };
        };
        return chars - (wideChars / 2);
    };
    return 0;
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
bool Base<T>::isLastBufCell(int y, int x) const
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        if (!this->buf.empty())
        {
            return this->buf[this->buf.size() - 1]->coords.y == y && this->buf[this->buf.size() - 1]->coords.x == x;
        };
    };
    return false;
};

template <typename T>
bool Base<T>::isRowEmpty(int y)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto buf = this->getBufferIterator();
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i]->coords.y == y)
            {
                return false;
            };
        };
    };
    return true;
};

template <typename T>
bool Base<T>::isBufCell(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto buf = this->getBufferIterator();
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i]->coords.y == y && buf[i]->coords.x == x && buf[i]->symbol != ' ')
            {
                return true;
            };
        };
    };
    return false;
};

template <typename T>
void Base<T>::removeCharsBetweenSpaces(int y, int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
    };
};

template class Buffer<BufferCellOnlyWithSymbol>;
template class Buffer<BufferCellOnlyWithCoords>;
template class Buffer<BufferCellWithCoords>;
template class Buffer<BufferCellWithSymbolType>;

template class Base<BufferCellOnlyWithSymbol>;
template class Base<BufferCellOnlyWithCoords>;
template class Base<BufferCellWithCoords>;
template class Base<BufferCellWithSymbolType>;

template class CoordsTranslocation<BufferCellOnlyWithSymbol>;
template class CoordsTranslocation<BufferCellOnlyWithCoords>;
template class CoordsTranslocation<BufferCellWithCoords>;
template class CoordsTranslocation<BufferCellWithSymbolType>;

Buffer<BufferCellWithSymbolType> *_LOG__BUF = new Buffer<BufferCellWithSymbolType>;
Buffer<BufferCellOnlyWithSymbol> *_DEFAULT__BUF = new Buffer<BufferCellOnlyWithSymbol>;
Buffer<BufferCellWithCoords> *_INSERT__BUF = new Buffer<BufferCellWithCoords>;
Buffer<BufferCellWithCoords> *_COMMAND__BUF = new Buffer<BufferCellWithCoords>;
Buffer<BufferCellWithCoords> *_EFFECTS__BUF = new Buffer<BufferCellWithCoords>;
Buffer<BufferCellOnlyWithCoords> *_SEARCH__BUF = new Buffer<BufferCellOnlyWithCoords>;
