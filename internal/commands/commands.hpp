#include <vector>
#include <string>

class CommandInterface{
    virtual void execute();
};

class CommandTools{
    void set_command(char s);

    std::string get_command();

    void delete_command();

    void pop_symbol_from_command();

    void apply_command(std::string c);
};