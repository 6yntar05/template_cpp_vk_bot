#ifndef BOT_HANDLERS_MESSAGE_NEW_HPP
#define BOT_HANDLERS_MESSAGE_NEW_HPP

#include "commands/base.hpp"

#include "cpp_vk_lib/vk/include/events/message_new.hpp"

#include <memory>
#include <unordered_map>

namespace bot {

class message_new_handler {
public:
    void process(vk::event::message_new&& event) const;

    template <typename Handler>
    message_new_handler& on_command(std::string_view trigger);

private:
    std::unordered_map<std::string, std::shared_ptr<command::base>> commands_{};
};

template <typename Handler>
bot::message_new_handler& bot::message_new_handler::on_command(std::string_view trigger) {
    commands_.emplace(trigger, std::make_unique<Handler>());
    return *this;
}

}// namespace bot

#endif// BOT_HANDLERS_MESSAGE_NEW_HPP
