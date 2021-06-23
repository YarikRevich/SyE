#include <iostream>
#include <string>
#include <stdio.h>

class DevLog
{
private:
    FILE *file;

public:
    void prepare_file();

    void write_to_file_str(std::string);

    void write_to_file_chr(char);

    FILE *get_file();

    void close_file();
};