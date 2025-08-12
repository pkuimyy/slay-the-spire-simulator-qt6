#pragma once

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace core {

inline void initLogging(const spdlog::level::level_enum level = spdlog::level::info) {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_pattern("[%H:%M:%S] [%^%l%$] %v");

    const auto logger = std::make_shared<spdlog::logger>("core_logger", console_sink);
    logger->set_level(level);
    logger->flush_on(spdlog::level::trace);
    spdlog::set_default_logger(logger);
}

}  // namespace core
