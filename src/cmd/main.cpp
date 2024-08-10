#include "../internal/logger/logger.hpp"
#include "../internal/command/handler/handler.hpp"

/**
 * Entrypoint, to propagate logic to the handler.
*/
int main(int argc, char **argv) {
    auto* handler = new Handler(argc, argv);

    if (handler->run() != EXIT_SUCCESS) {
        if (Logger::IsErrorExist()) {
            std::cout << Logger::GetError() << std::endl;
        }
    }
}