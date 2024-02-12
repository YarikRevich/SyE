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
    std::cout << message << std::endl;
};