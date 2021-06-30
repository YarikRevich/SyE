/*
    Contains general types and interfaces
    used over the project
*/

#pragma once

#include <vector>

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
template <class T>
class BufferInterface
{
protected:
    std::vector<T> buf;

    //Says if buffer is modified
    bool modified;

public:
    //Deletes equal cell in buffer
    void erase(int y, int x);

    //Appends cell to the end of the buffer with coords
    void add_C(int s, int y, int x);

    //Appends cell to the end of the buffer
    void add(int s);

    // Sets fully new buffer
    void set(std::vector<T> b);

    //Returns buffer
    std::vector<T> get();

    // Sets modified state
    void set_modified(bool s);

    // Returns modified attr
    bool is_modified();
};

//Interface for all handlers
class HandlerInterface
{
public:
    //Just handle pressed key
    virtual void handle(int ch);
};

class AddonFileInterface
{
public:
    virtual void auto_save();
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
    virtual void open(char n[]);

    virtual std::string read();

    virtual void save();

    virtual void close();
};
