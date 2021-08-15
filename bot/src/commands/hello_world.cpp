#include "commands/hello_world.hpp"

#include "cpp_vk_lib/vk/include/events/message_new.hpp"
#include "cpp_vk_lib/vk/include/methods/basic.hpp"

namespace bot::command {

void hello_world::execute(const vk::event::message_new& event, const std::vector<std::string_view>&) const
{
    vk::method::messages::send(event.peer_id(), "Hello world from cpp_vk_lib :)");
}

}// namespace bot::command