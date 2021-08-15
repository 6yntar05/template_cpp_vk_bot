#ifndef BOT_COMMANDS_BASE_HPP
#define BOT_COMMANDS_BASE_HPP

#include <vector>
#include <string_view>

namespace vk::event {
class message_new;
}// namespace vk::event

namespace bot {
namespace command {

class base
{
public:
    virtual void execute(const vk::event::message_new& event, const std::vector<std::string_view>& args) const = 0;
    virtual ~base() = default;
};

}// namespace command
}// namespace bot

#endif// BOT_COMMANDS_BASE_HPP
