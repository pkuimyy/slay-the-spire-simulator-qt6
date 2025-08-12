#include "util/logging.h"

int main(int argc, char **argv) {
    core::initLogging(spdlog::level::debug);

    spdlog::debug("Debug log after initLogging");
    spdlog::info("Info log after initLogging");
    spdlog::warn("Warn log after initLogging");

    const auto level = spdlog::default_logger()->level();
    spdlog::info("Current logger level is {}", spdlog::level::to_string_view(level));
    return 0;
}
