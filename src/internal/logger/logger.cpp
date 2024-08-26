#include "logger.hpp"

std::string Logger::message;

bool Logger::isErrorExist() {
    return !message.empty();
}

std::string Logger::getError() {
    return message;
}

void Logger::setError(std::string message) {
    std::stringstream ss;

    ss << "ERROR: " << message << std::endl;

    Logger::message = ss.str();
}

void Logger::invokeWarning(std::string message) {
    printf("WARNING: %s\n", message.c_str());
};

void Logger::invokeInfo(std::string message) {
    printf("INFO: %s\n", message.c_str());
};