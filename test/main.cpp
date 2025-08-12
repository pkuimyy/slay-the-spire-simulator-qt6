#include <gtest/gtest.h>

#include "util/logging.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    core::initLogging(spdlog::level::debug);
    return RUN_ALL_TESTS();
}
