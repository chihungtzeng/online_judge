project(leet)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(leet main.cpp leet.cpp leet_test.cpp)
target_link_libraries(leet gtest)
