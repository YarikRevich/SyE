#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <type_traits>

bool isInsertSameToDefaultBuf();

typedef struct CellCoords
{
    int y;
    int x;
} CellCoords;

typedef struct
{
    int symbol;
    CellCoords coords;
    bool sentenceHyphenation;
    std::string fontColor;
} BufferCellWithCoords;

typedef struct
{
    int y;
    std::string text;
} BufferAsString;

typedef struct
{
    int symbol;
} BufferCellOnlyWithSymbol;

typedef struct
{
    CellCoords coords;
} BufferCellOnlyWithCoords;

enum SymbolType
{
    CHAR,
    INT
};

typedef struct
{
    int symbol;
    SymbolType type;
} BufferCellWithSymbolType;

template <typename T>
class Base
{
protected:
    std::vector<T *> buf;

private:
    static bool sort(const T *, const T *);

public:
    bool isStartRow(const int) const;

    void addCellWithCoords(const int, const int, const int);

    void addCellWithSymbolType(const int, const SymbolType st);

    void addCellOnlyWithSymbol(const int);

    void addCellOnlyWithCoords(const int, const int);

    void addCellToEnd(const int);

    void addEolIfNotExists();

    void setCellWithCoordsColor(const int y, const int x, const std::string color);

    void setCellSentenceHyphenation(const int y, const int x, const bool status);

    bool cellIsSentenceHyphenation(const int y, const int x);

    std::tuple<int, int> getEndOfSentence(const int y, const int x);

    std::vector<T *> &getBufferIterator();

    std::string getBufAsString();

    std::vector<BufferAsString> getBufAsStringWithYCoord();

    int getLastXInRow(const int);

    std::vector<BufferCellWithCoords *> getRowWithY(const int);

    BufferCellOnlyWithCoords *getPrevCellByCoords(const int, const int) const;

    BufferCellOnlyWithCoords *getNextCellByCoords(const int, const int) const;

    bool isLastBufCell(const int, const int);

    bool isRowEmpty(const int);

    bool isBufCell(const int, const int);

    std::tuple<int, int> deleteWordBeforeSpace(const int, const int);

    void eraseCell(const int, const int);

    void clearBuf();
};

template <typename T>
class CoordsTranslocation : public Base<T>
{
public:
    void translocateYUp() const;

    void translocateYDown() const;

    void translocateYUpAfter(const int) const;

    void translocateYDownAfter(const int) const;

    void translocateXRightAfter(const int, const int) const;

    void translocateXLeftAfter(const int, const int) const;
};

class Status
{
protected:
    bool modified;

public:
    void setModified(const bool s);

    bool isModified() const;
};

template <typename T>
class Buffer : public CoordsTranslocation<T>, public Status
{
};

extern template class Buffer<BufferCellOnlyWithSymbol>;
extern template class Buffer<BufferCellOnlyWithCoords>;
extern template class Buffer<BufferCellWithCoords>;
extern template class Buffer<BufferCellWithSymbolType>;

extern template class Base<BufferCellOnlyWithSymbol>;
extern template class Base<BufferCellOnlyWithCoords>;
extern template class Base<BufferCellWithCoords>;
extern template class Base<BufferCellWithSymbolType>;

extern template class CoordsTranslocation<BufferCellOnlyWithSymbol>;
extern template class CoordsTranslocation<BufferCellOnlyWithCoords>;
extern template class CoordsTranslocation<BufferCellWithCoords>;
extern template class CoordsTranslocation<BufferCellWithSymbolType>;

extern Buffer<BufferCellWithSymbolType> *_LOG__BUF;
extern Buffer<BufferCellOnlyWithSymbol> *_DEFAULT__BUF;
extern Buffer<BufferCellWithCoords> *_INSERT__BUF;
extern Buffer<BufferCellWithCoords> *_COMMAND__BUF;
extern Buffer<BufferCellWithCoords> *_EFFECTS__BUF;
extern Buffer<BufferCellOnlyWithCoords> *_SEARCH__BUF;

extern Buffer<BufferCellWithCoords> *_TIME_WIDGET__BUF;