#pragma once

#include <string>
#include <vector>
#include <tuple>

bool isInsertSameToDefaultBuf();

typedef struct
{
    int y;
    std::string text;
} BufferAsString;

typedef struct{
    bool isStartOfChar;
    bool isEndOfChar;
} WideChar;

typedef struct
{
    WideChar wideChar;

    int symbol;
    int y;
    int x;
    bool sentenceHyphenation;
    std::string fontColor;
} BufferCellWithCoords;

typedef struct
{
    int symbol;
} BufferCell;

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

    void createID();

private:
    int id;

    static bool sort(T *currentBufferCell, T *nextBufferCell);

public:
    int getID();

    bool isStartRow(int y);

    void addStartWideCharCellWithCoords(int s, int y, int x);

    void addEndWideCharCellWithCoords(int s, int y, int x);

    bool isWideCharStarted(int y, int x);

    bool isStartOfWideChar(int y, int x);

    bool isEndOfWideChar(int y, int x);

    void addCellWithCoords(int s, int y, int x);

    void addCellWithSymbolType(int s, SymbolType st);

    void addCell(int s);

    void addCellToEnd(int s);

    void addEolIfNotExists();

    void setCellWithCoordsColor(int y, int x, std::string color);

    void setCellSentenceHyphenation(int y, int x, bool status);

    bool cellIsSentenceHyphenation(int y, int x);

    std::tuple<int, int> getEndOfSentence(int y, int x);

    std::vector<T *> getBufferIterator();

    std::string getBufAsString();

    std::vector<BufferAsString> getBufAsStringWithYCoord();

    int getLastXInRow(int y);

    std::vector<BufferCellWithCoords *> getRowWithY(int y);

    bool isLastBufCell(int y, int x);

    bool isRowEmpty(int y);

    bool isBufCell(int y, int x);

    void eraseCell(int y, int x);

    void clearBuf();
};

template <typename T>
class CoordsTranslocation : public Base<T>
{
public:
    void translocateYUp();

    void translocateYDown();

    void translocateYUpAfter(int y);

    void translocateYDownAfter(int y);

    void translocateXRightAfter(int y, int x);

    void translocateXLeftAfter(int y, int x);
};

class Movement
{
protected:
    std::tuple<int, int> movement;
    bool empty = true;
    bool ignoreForcibleMove;

public:
    void setMovement(int y, int x);

    std::tuple<int, int> getMovement();

    void deleteMovement();

    bool isEmpty();

    void setIgnoreForcibleMove(bool s);

    bool isIgnoreForcibleMove();

    void resetIgnoreForcibleMove();
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
class Buffer : public CoordsTranslocation<T>, public Movement, public Status
{
public:
    Buffer();
};

extern Buffer<BufferCellWithSymbolType> *_LOG__BUF;
extern Buffer<BufferCell> *_DEFAULT__BUF;
extern Buffer<BufferCellWithCoords> *_INSERT__BUF;
extern Buffer<BufferCellWithCoords> *_COMMAND__BUF;
extern Buffer<BufferCellWithCoords> *_EFFECTS__BUF;
extern Buffer<BufferCellWithCoords> *_SEARCH__BUF;