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
    static bool sort(T *currentBufferCell, T *nextBufferCell);

public:
    bool isStartRow(int y);

    void addCellWithCoords(int s, int y, int x);

    void addCellWithSymbolType(int s, SymbolType st);

    void addCellOnlyWithSymbol(int s);

    void addCellOnlyWithCoords(int y, int x);

    void addCellToEnd(int s);

    void addEolIfNotExists();

    void setCellWithCoordsColor(int y, int x, std::string color);

    void setCellSentenceHyphenation(int y, int x, bool status);

    bool cellIsSentenceHyphenation(int y, int x);

    std::tuple<int, int> getEndOfSentence(int y, int x);

    std::vector<T *> &getBufferIterator();

    std::string getBufAsString();

    std::vector<BufferAsString> getBufAsStringWithYCoord();

    int getLastXInRow(int y);

    std::vector<BufferCellWithCoords *> getRowWithY(int y);

    BufferCellOnlyWithCoords *getPrevCellByCoords(int y, int x);

    BufferCellOnlyWithCoords *getNextCellByCoords(int y, int x);

    bool isLastBufCell(int y, int x) const;

    bool isRowEmpty(int y);

    bool isBufCell(int y, int x);

    void removeCharsBetweenSpaces(int y, int x);

    void eraseCell(int y, int x);

    void clearBuf();
};

template <typename T>
class CoordsTranslocation : public Base<T>
{
public:
    void translocateYUp() const;

    void translocateYDown();

    void translocateYUpAfter(int y);

    void translocateYDownAfter(int y);

    void translocateXRightAfter(int y, int x);

    void translocateXLeftAfter(int y, int x);
};

class Status
{
protected:
    bool modified;

public:
    void setModified(bool s);

    bool isModified();
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