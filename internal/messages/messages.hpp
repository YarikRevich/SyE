#pragma once

#include <vector>

class PrinterInterface
{
private:
    std::vector<void *> messages;

public:
    virtual void print() = 0;
};

class MessageWriter
{
public:
    MessageWriter(std::vector<PrinterInterface>);
};

class RedPrinter : public PrinterInterface
{
public:
    RedPrinter(std::vector<void *>);

    void print();
};
