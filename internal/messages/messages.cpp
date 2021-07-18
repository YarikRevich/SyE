#include <vector>
#include <iostream>
#include "messages.hpp"

RedPrinter::RedPrinter(std::vector<std::string> messages)
{
    this->messages = messages;
};

RedPrinter::print()
{
    for (int i = 0; i < this->messages.size(); i++)
    {
        std::cout << "\033[31m" << this->messages[i] << " " << "\033[0m";
    };
};

MessageWriter::MessageWriter(std::vector<PrinterInterface> printers)
{
    for (int i = 0; i < printers.size(); i++)
    {
        printers[i].print();
    };
    exit(1);
};
