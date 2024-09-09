project(Explorer)
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

add_executable(explorer explorer.cpp)

IF (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_target(t1 COMMAND ./explorer < ${CMAKE_SOURCE_DIR}/in.txt && echo "===" && cat ${CMAKE_SOURCE_DIR}/out.txt)
    add_custom_target(t2 COMMAND ./explorer < ${CMAKE_SOURCE_DIR}/in2.txt && echo "===" && cat ${CMAKE_SOURCE_DIR}/out2.txt)
    add_custom_target(t3 COMMAND ./explorer < ${CMAKE_SOURCE_DIR}/in3.txt && echo "===" && cat ${CMAKE_SOURCE_DIR}/out3.txt)
    add_custom_target(t4 COMMAND ./explorer < ${CMAKE_SOURCE_DIR}/in4.txt && echo "===" && cat ${CMAKE_SOURCE_DIR}/out4.txt)
    add_custom_target(t5 COMMAND ./explorer < ${CMAKE_SOURCE_DIR}/in5.txt && echo "===" && cat ${CMAKE_SOURCE_DIR}/out5.txt)
    add_custom_target(t6 COMMAND ./explorer < ${CMAKE_SOURCE_DIR}/in6.txt && echo "===" && cat ${CMAKE_SOURCE_DIR}/out6.txt)
ENDIF ()
IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_custom_target(t1 COMMAND ./explorer)
ENDIF ()
