#include "message_new_handler.hpp"
#include "string_utils.hpp"

#include "runtime/include/string_utils/string_utils.hpp"

#include "spdlog/spdlog.h"

void bot::message_new_handler::process(vk::event::message_new&& event) const
{
    spdlog::info("Message event: {} from {}", event.text(), event.peer_id());

    if (!event.has_action()) {
        commands_.at(string_util::get_first(event.text()))->execute(
            event,
            runtime::string_utils::whitespace_split(string_util::cut_first(event.text())));
        return;
    }
}
