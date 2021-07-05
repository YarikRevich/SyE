/*
    Contains general types and interfaces
    used over the project
*/

#pragma once

#include <vector>
#include <string>

//Used for units in buffers (including coords)
typedef struct
{
    int symbol;
    int y;
    int x;
} buf_cell_C;

//Used for units in buffers
typedef struct
{
    int symbol;
} buf_cell;

enum L_symbol_type
{
    CHAR,
    INT
};

//Used for units in log buffer
typedef struct
{
    int symbol;
    L_symbol_type type;
} buf_cell_L;

//Interface for all buffers
template <typename T>
class BufferInterface
{
private:
    std::vector<T *> buf;

    //Says if buffer is modified
    bool modified;

    std::tuple<int, int> move;

    bool empty = true;

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
    void translocation_right_after_x(int x);

    //Says if cell with such coords is the last in the buffer
    bool is_last_cell(int y, int x);
};

//Interface for all handlers
class HandlerInterface
{
public:
    //Just handle pressed key
    virtual void handle(int ch) = 0;
};

class AddonFileInterface
{
public:
    virtual void auto_save() = 0;
};

//Interface for all files(executable, log, config)
class FileInterface
{
protected:
    std::string file_name;
    FILE *file;

public:
    //If file does not exist it will create it,
    //but if it does it just opens it
    virtual void open(char n[]) = 0;

    virtual std::string read() = 0;

    virtual void save() = 0;

    virtual void close() = 0;
};
