#include <math.h>
#include <cmath>
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
void CoordsTranslocation<T>::translocateYUpAfter(const int y) const
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
void CoordsTranslocation<T>::translocateYDown() const
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
void CoordsTranslocation<T>::translocateYDownAfter(const int y) const
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
void CoordsTranslocation<T>::translocateXRightAfter(const int y, const int x) const
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
void CoordsTranslocation<T>::translocateXLeftAfter(const int y, const int x) const
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
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
};

template <typename T>
bool Base<T>::sort(const T *nextBufferCell, const T *currentBufferCell)
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
bool Base<T>::isStartRow(const int y) const
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
BufferCellOnlyWithCoords *Base<T>::getPrevCellByCoords(const int y, const int x) const
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
BufferCellOnlyWithCoords *Base<T>::getNextCellByCoords(const int y, const int x) const
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
void Base<T>::eraseCell(const int y, const int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        if (buffer.size() > 1)
        {
            int index_of_cell_to_delete = 0;

            for (int i = 0; i < buffer.size(); i++)
            {
                if (buffer[i]->coords.x == x && buffer[i]->coords.y == y)
                {
                    index_of_cell_to_delete = i;
                }
            };

            buffer.erase(buffer.begin() + index_of_cell_to_delete);

            if (!std::signbit(index_of_cell_to_delete - 1))
            {
                if (buffer[index_of_cell_to_delete - 1]->coords.y == y && buffer[index_of_cell_to_delete - 1]->coords.x == x)
                {
                    if (buffer[index_of_cell_to_delete - 1]->symbol != 32)
                    {
                        buffer.erase(buffer.begin() + index_of_cell_to_delete - 1);
                    }
                }
            }
        }
        else if (buffer.size() != 0)
        {
            buffer.erase(buffer.begin());
        };
    };
}

template <typename T>
void Base<T>::addCellWithCoords(const int s, const int y, const int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        BufferCellWithCoords *b = new BufferCellWithCoords;
        b->symbol = s;
        b->coords.y = y;
        b->coords.x = x;
        b->sentenceHyphenation = false;

        auto &buffer = this->getBufferIterator();
        buffer.push_back(b);

        // std::sort(this->buf.begin(), this->buf.end(), this->sort);
    };
}

template <typename T>
void Base<T>::addCellWithSymbolType(const int s, const SymbolType st)
{
    if constexpr (buffer_assertion(T, BufferCellWithSymbolType))
    {
        BufferCellWithSymbolType *b = new BufferCellWithSymbolType;
        b->symbol = s;
        b->type = st;

        auto &buffer = this->getBufferIterator();
        buffer.push_back(b);
    };
};

template <typename T>
void Base<T>::addCellOnlyWithSymbol(const int s)
{
    if constexpr (buffer_assertion(T, BufferCellOnlyWithSymbol))
    {
        BufferCellOnlyWithSymbol *b = new BufferCellOnlyWithSymbol;
        b->symbol = s;

        auto &buffer = this->getBufferIterator();
        buffer.push_back(b);
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

        auto &buffer = this->getBufferIterator();
        buffer.push_back(b);
    };
};

template <typename T>
void Base<T>::addCellToEnd(const int s)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();

        auto last_cell = buffer[buffer.size() - 1];

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

        buffer.push_back(b);
    };
};

template <typename T>
void Base<T>::addEolIfNotExists()
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        if (buffer.begin() != buffer.end())
        {
            if (buffer[buffer.size() - 1]->symbol != 10)
            {
                T *b = new T;
                b->symbol = 10;

                buffer.push_back(b);
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
void Base<T>::setCellWithCoordsColor(const int y, const int x, const std::string color)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        for (int i = 0; i < buffer.size(); i++)
        {
            if (buffer[i]->coords.y == y && buffer[i]->coords.x == x)
            {
                buffer[i]->fontColor = color;
            };
        };
    };
};

template <typename T>
void Base<T>::setCellSentenceHyphenation(const int y, const int x, const bool status)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        for (int i = 0; i < buffer.size(); i++)
        {
            if (buffer[i]->coords.y == y && buffer[i]->coords.x == x)
            {
                buffer[i]->sentenceHyphenation = status;
            };
        };
    };
};

template <typename T>
bool Base<T>::cellIsSentenceHyphenation(const int y, const int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        for (int i = 0; i < buffer.size(); i++)
        {
            if (buffer[i]->coords.y == y && buffer[i]->coords.x == x)
            {
                return buffer[i]->sentenceHyphenation;
            };
        };
    };
    return false;
}

template <typename T>
std::tuple<int, int> Base<T>::getEndOfSentence(const int y, const int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        for (int i = 0; i < buffer.size(); i++)
        {
            if (buffer[i]->coords.y >= y && !this->cellIsSentenceHyphenation(buffer[i]->coords.y, this->getLastXInRow(buffer[i]->coords.y)))
            {
                return {buffer[i]->coords.y, buffer[i]->coords.x};
            };
        };
    };
    return {0, 0};
};

template <typename T>
std::vector<BufferCellWithCoords *> Base<T>::getRowWithY(const int y)
{
    std::vector<BufferCellWithCoords *> res;
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        for (int i = 0; i < buffer.size(); ++i)
        {
            if (buffer[i]->coords.y == y)
            {
                res.push_back(buffer[i]);
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
int Base<T>::getLastXInRow(const int y)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        int chars = 0;
        int wideChars = 0;
        auto &buffer = this->getBufferIterator();
        for (int i = 0; i < buffer.size(); i++)
        {
            if ((buffer[i]->coords.y == y) && (buffer[i]->symbol != 10))
            {
                if (i != 0)
                {
                    if (buffer[i - 1]->coords.y == y && buffer[i - 1]->coords.x == buffer[i]->coords.x)
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

void Status::setModified(const bool s)
{
    this->modified = s;
};

bool Status::isModified() const
{
    return this->modified;
}

template <typename T>
void Base<T>::clearBuf()
{
    auto &buffer = this->getBufferIterator();
    buffer.erase(buffer.begin(), buffer.end());
};

template <typename T>
bool Base<T>::isLastBufCell(const int y, const int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        if (!buffer.empty())
        {
            return buffer[buffer.size() - 1]->coords.y == y && buffer[buffer.size() - 1]->coords.x == x;
        };
    };
    return false;
};

template <typename T>
bool Base<T>::isRowEmpty(const int y)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        for (int i = 0; i < buffer.size(); i++)
        {
            if (buffer[i]->coords.y == y)
            {
                return false;
            };
        };
    };
    return true;
};

template <typename T>
bool Base<T>::isBufCell(const int y, const int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto buffer = this->getBufferIterator();
        for (int i = 0; i < buffer.size(); i++)
        {
            if (buffer[i]->coords.y == y && buffer[i]->coords.x == x && buffer[i]->symbol != ' ')
            {
                return true;
            };
        };
    };
    return false;
};

template <typename T>
std::tuple<int, int> Base<T>::deleteWordBeforeSpace(const int y, const int x)
{
    if constexpr (buffer_assertion(T, BufferCellWithCoords))
    {
        auto &buffer = this->getBufferIterator();
        bool traced_chars = false;

        for (int i = buffer.size() - 1; i > -1; --i)
        {
            if (buffer[i]->symbol != ' ')
            {
                traced_chars = true;
            }
            if (traced_chars && buffer[i]->symbol == ' ')
            {
                return {buffer[i]->coords.y, buffer[i]->coords.x};
            }

            this->eraseCell(buffer[i]->coords.y, buffer[i]->coords.x);
        };
    };
    return {0, 0};
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
