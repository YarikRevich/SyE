#pragma once

class Message
{
private:
    void *message;

public:
    Message(void *);
    void *get();
};

class MessageWriter
{
public:
    MessageWriter(std::vector<PrinterInterface>);
};

class PrinterInterface
{
public:
    virtual void get()
};

class RedPrinter : PrinterInterface
{
    std::vector<Message> messages;

public:
    RedPrint(std::vector<Message>);

    void *get();
};

//MessageWriter(RedPrinter("Hello"));
