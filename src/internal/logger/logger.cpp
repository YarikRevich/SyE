#include "logger.hpp"

std::string Logger::message("");

bool Logger::IsErrorExist() {
    return !message.empty();
}

std::string Logger::GetError() {
    return message;
}

void Logger::SetError(std::string message) {
    Logger::message = message;
}

void Logger::InvokeWarning(std::string message) {
    printf("WARNING: %s\n", message.c_str());
};

void Logger::InvokeInfo(std::string message) {
    printf("INFO: %s\n", message.c_str());
};