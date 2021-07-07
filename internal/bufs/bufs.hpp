#pragma once

#include "./../index.hpp"


bool is();

typedef struct
{
    int symbol;
    int y;
    int x;
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
class BufferInterface
{
private:
    std::vector<T *> buf;

    //Says if buffer is modified
    bool modified;

    std::tuple<int, int> move;

    bool empty = true;

    bool ignore_forcible_move;

    //Sorts buffer by y and x coords
    static bool sort(T *f, T *s);

public:
    //Says if coords are the start of the file
    bool is_start(int y);

    //Deletes equal cell in buffer
    void erase(int y, int x);

    //Deletes the last element from buffer
    void pop();

    //Appends cell to the end of the buffer with coords
    void add_C(int s, int y, int x);

    //Appends cell to the buffer with symbol type
    void add_L(int s, L_symbol_type st);

    //Appends cell to the end of the buffer
    void add(int s);

    //Sets move for render
    void set_move(int y, int x);

    //Returns move for render
    std::tuple<int, int> get_move();

    //Deletes move for render
    void delete_move();

    //Says if set move function was used
    //Because if it didn't it can cause
    //death loop of printing chars
    bool is_empty();

    // Sets modified state
    void set_modified(bool s);

    // Returns modified attr
    bool is_modified();

    // Sets fully new buffer
    void set(std::vector<T *> b);

    //Returns buffer
    std::vector<T *> get();

    //Returns buffer as string
    std::string get_as_string();

    //Returns the last x in the row
    int get_last_x(int y);

    //Clears the whole buffer
    void clear();

    //Translocates y coords up
    void translocation_up();

    //Translocates y coords up from the equal y coord
    void translocation_up_after_y(int y);

    //Translocates y coord sdown
    void translocation_down();

    //Translocates y coords up from the equal y coord
    void translocation_down_after_y(int y);

    //Translocates x coords right from the equal x coord
    void translocation_right_after_x(int y, int x);

    //Translocates x coords right from the equal x coord
    void translocation_left_after_x(int y, int x);

    //Says if cell with such coords is the last in the buffer
    bool is_last_cell(int y, int x);

    void set_ignore_forcible_move(bool s);

    bool is_ignore_forcible_move();
};

extern BufferInterface<BufferCellWithSymbolType> *_LOG__BUF;
extern BufferInterface<BufferCell> *_DEFAULT__BUF;
extern BufferInterface<BufferCellWithCoords> *_INSERT__BUF;
extern BufferInterface<BufferCellWithCoords> *_COMMAND__BUF;
extern BufferInterface<BufferCellWithCoords> *_EFFECTS__BUF;
extern BufferInterface<BufferCellWithCoords> *_SEARCH__BUF;