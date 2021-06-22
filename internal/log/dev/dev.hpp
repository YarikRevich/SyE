#include <iostream>
#include <stdio.h>

class DevLog
{
private:
    FILE *file;

public:
    void prepare_file();

    void write_to_file(const char s[]);

    FILE *get_file();

    void close_file();
};