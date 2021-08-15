#ifndef BOT_LONG_POLLER_HPP
#define BOT_LONG_POLLER_HPP

#include "message_new_handler.hpp"

#include "cpp_vk_lib/vk/include/long_poll/long_poll.hpp"

namespace bot {

class long_poller
{
public:
    long_poller(asio::io_context& io_context);

    message_new_handler& get_message_handler() noexcept;
    void run();

private:
    vk::long_poll lp_;
    message_new_handler message_handler_{};
};

}// namespace bot

#endif// BOT_LONG_POLLER_HPP
