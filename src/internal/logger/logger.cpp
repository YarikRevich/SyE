#include "logger.hpp"

std::string Logger::message("");

bool Logger::IsErrorExist() {
    return !message.empty();
}

std::string Logger::GetError() {
    return message;
}

void Logger::SetError(std::string message) {
    std::stringstream ss;

    ss << "ERROR: " << message << std::endl;

    Logger::message = ss.str();
}

void Logger::InvokeWarning(std::string message) {
    printf("WARNING: %s\n", message.c_str());
};

void Logger::InvokeInfo(std::string message) {
    printf("INFO: %s\n", message.c_str());
};