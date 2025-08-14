#pragma once
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace core {

inline std::shared_ptr<spdlog::logger>& getLogger() {
    static std::shared_ptr<spdlog::logger> logger = [] {
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(spdlog::level::debug);
        console_sink->set_pattern("[%^%l%$] %v");

        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/multisink.txt", true);
        file_sink->set_level(spdlog::level::debug);

        auto default_logger =
            std::make_shared<spdlog::logger>("global_logger", spdlog::sinks_init_list{console_sink, file_sink});
        default_logger->set_level(spdlog::level::debug);
        default_logger->flush_on(spdlog::level::trace);

        spdlog::register_logger(default_logger);
        spdlog::set_default_logger(default_logger);

        return default_logger;
    }();
    return logger;
}

}  // namespace core
