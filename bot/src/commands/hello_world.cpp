#include "commands/hello_world.hpp"

#include "cpp_vk_lib/vk//events/message_new.hpp"
#include "cpp_vk_lib/vk//methods/basic.hpp"

namespace bot {

void command::hello_world(const vk::event::message_new& event, const std::vector<std::string_view>&)
{
    vk::method::messages::send(event.peer_id(), "Hello world from cpp_vk_lib :)");
}

}// namespace bot