/*
    Contains general types and interfaces
    used over the project
*/

#pragma once

#include <vector>

//Used for units in buffers
typedef struct
{
    int symbol;
    int y;
    int x;
} buf_cell;

//Interface for all buffers
class BufferInterface
{
protected:
    std::vector<buf_cell> buf;

    //Says if buffer is modified
    bool modified;

public:
    //Deletes equal cell in buffer
    void erase(int y, int x);

    //Appends cell to the end of the buffer
    void add(int s, int y, int x);

    /*
        Sets fully new buffere
        @additional
    */
    void set();

    //Returns buffer
    std::vector<buf_cell> get();

    /*
        Sets modified state
        @additional
    */
    void set_modified(bool s);

    /*
        Returns modified attr
        @additional
    */
    bool is_modified();
};

//Interface for all handlers
class HandlerInterface
{
public:
    //Just handle pressed key
    virtual void handle(int ch);
};

class FileInterface
{
};
