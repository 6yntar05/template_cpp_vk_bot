#ifndef BOT_COMMANDS_HELLO_WORLD_HPP
#define BOT_COMMANDS_HELLO_WORLD_HPP

#include "commands/base.hpp"

namespace bot::command {

class hello_world final : public base
{
public:
    void execute(const vk::event::message_new& event, const std::vector<std::string_view>& args) const override;
};

}// namespace bot::command

#endif //BOT_COMMANDS_HELLO_WORLD_HPP
