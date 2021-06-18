#include <stdio.h>
#include <vector>

typedef struct
{
    int symbol;
    int y;
    int x;
} buf_cell;

class File
{

private:
    std::vector<buf_cell> buf;
    bool OPEN;
    FILE *file;

public:
    void prepare_file(int argc, char **argv);

    void delete_from_buffer(int y, int x);

    void save_to_buffer(int s, int y, int x);

    void write_to_file();

    void close_file();
};