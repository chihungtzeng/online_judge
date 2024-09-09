project(leet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fno-omit-frame-pointer -fno-optimize-sibling-calls -fsanitize=address")

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(leet main.cpp leet.cpp leet_test.cpp)
target_link_libraries(leet gtest)
