#include "util/logging.h"

int main(int argc, char **argv) {
    spdlog::debug("Debug log after initLogging");
    spdlog::info("Info log after initLogging");
    spdlog::warn("Warn log after initLogging");
    return 0;
}
