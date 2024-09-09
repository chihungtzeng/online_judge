project(3n+1)
cmake_minimum_required(VERSION 3.0)

IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall -Wextra")
ELSE ()
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall -Wextra -DONLINE_JUDGE")
ENDIF ()

IF (USE_GPROF)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
ENDIF ()

IF (USE_ASAN)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
ENDIF ()

SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")

add_executable(100 main.cpp)
add_executable(unordered_map unordered_map.cpp)
add_executable(main_class main_class.cpp)
#enable_testing()
#add_test(NAME std_test COMMAND 100 < ${CMAKE_SOURCE_DIR}/in.txt)
