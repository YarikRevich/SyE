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

//Interface for all buffers
template <typename T>
class BufferInterface
{
protected:
    std::vector<T *> buf;

    //Says if buffer is modified
    bool modified;

public:
    //Says if coords are the start of the file
    bool is_start(int y);

    //Deletes equal cell in buffer
    void erase(int y, int x);

    //Deletes the last element from buffer
    void pop();

    //Appends cell to the end of the buffer with coords
    void add_C(int s, int y, int x);

    //Appends cell to the end of the buffer
    void add(int s);

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

    //Translocates y coord up
    void translocation_up();

    //Translocates y coord down
    void translocation_down();
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
