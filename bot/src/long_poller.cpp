#include "long_poller.hpp"

bot::long_poller::long_poller(asio::io_context& io_context)
    : lp_(io_context) {}

bot::message_new_handler& bot::long_poller::get_message_handler() noexcept
{
    return message_handler_;
}

void bot::long_poller::run()
{
    while (true) {
        auto events = lp_.listen(60);
        for (auto& event : events) {
            lp_.on_event("message_new", event, [this, &event] {
                message_handler_.process(event.get_message_new());
            });
        }
        lp_.run();
    }
}
