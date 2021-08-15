#include "commands/hello_world.hpp"

#include "long_poller.hpp"

#include "cpp_vk_lib/vk/include/config/loader.hpp"
#include "cpp_vk_lib/vk/include/setup_logger.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Program requires path to config as the only argument." << std::endl;
        exit(-1);
    }
    using namespace bot;
    vk::config::load(argv[1]);
    vk::setup_logger("trace");
    spdlog::info("workers: {}", vk::config::num_workers());
    asio::io_context io_context;
    long_poller lp_handler(io_context);
    lp_handler.get_message_handler()
        .on_command<command::hello_world>("/hello_world");
    lp_handler.run();
    return EXIT_SUCCESS;
}
