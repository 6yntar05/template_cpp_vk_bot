include_directories(../modules/cpp_vk_lib)
include_directories(../modules/cpp_vk_lib/cpp_vk_lib/include)
include_directories(../modules/cpp_vk_lib/modules/spdlog/include)
include_directories(../modules/cpp_vk_lib/modules/asio/asio/include)
include_directories(include)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")

file(GLOB_RECURSE SRC "*.hpp" "*.cpp")
add_executable(template_bot ${SRC})

find_library(cpp_vk_lib HINTS "../cpp_vk_lib")
target_link_libraries(template_bot cpp_vk_lib)
