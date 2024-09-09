PROJECT(10706-NumSeq)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
SET(SOURCE_FILES "")
SET(INCLUDE_DIRS "")
SET(EXTRA_LIBRARIES "")

SET(USE_ASAN OFF CACHE BOOL "Use address sanitizer")
SET(USE_GTEST OFF CACHE BOOL "Use gtest")
SET(USE_BENCHMARK OFF CACHE BOOL "Use benchmark")

IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall -Wextra -Wno-unused-parameter -pg")
ELSE ()
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall -Wextra -Wno-unused-parameter -DONLINE_JUDGE -DNDEBUG")
ENDIF ()
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")

IF (USE_ASAN)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
ENDIF ()

IF (USE_GTEST)
    LIST(APPEND SOURCE_FILES 
        "gtest/src/gtest-all.cc"
        "gtest/src/gtest_main.cc"
        "${PROJECT_NAME}-ut.cpp"
        )
    LIST(APPEND INCLUDE_DIRS "gtest/include" "gtest")
    LIST(APPEND EXTRA_LIBRARIES "pthread")
    ADD_DEFINITIONS("-DENABLE_UNITTEST")
ELSEIF (USE_BENCHMARK)
    SET(BENCHMARK_DIR "benchmark")
    LIST(APPEND SOURCE_FILES 
    "${BENCHMARK_DIR}/src/benchmark.cc" 
    "${BENCHMARK_DIR}/src/colorprint.cc" 
    "${BENCHMARK_DIR}/src/commandlineflags.cc"
    "${BENCHMARK_DIR}/src/console_reporter.cc" 
    "${BENCHMARK_DIR}/src/csv_reporter.cc" 
    "${BENCHMARK_DIR}/src/json_reporter.cc" 
    "${BENCHMARK_DIR}/src/log.cc"
    "${BENCHMARK_DIR}/src/reporter.cc" 
    "${BENCHMARK_DIR}/src/sleep.cc" 
    "${BENCHMARK_DIR}/src/string_util.cc" 
    "${BENCHMARK_DIR}/src/sysinfo.cc" 
    "${BENCHMARK_DIR}/src/walltime.cc"
    "${BENCHMARK_DIR}/src/re_std.cc"
    "${PROJECT_NAME}-bench.cpp"
    )
    ADD_DEFINITIONS("-DENABLE_BENCHMARK -DHAVE_STD_REGEX")
    LIST(APPEND INCLUDE_DIRS "${BENCHMARK_DIR}/include")
    LIST(APPEND EXTRA_LIBRARIES "pthread")
ELSE ()
    LIST(APPEND SOURCE_FILES "${PROJECT_NAME}.cpp")
ENDIF()

SET(EXEC ${PROJECT_NAME})
ADD_EXECUTABLE(${EXEC} ${SOURCE_FILES})
INCLUDE_DIRECTORIES(${INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${EXEC} ${EXTRA_LIBRARIES})
SET(INPUT "${CMAKE_SOURCE_DIR}/in1.txt")
SET(EXPECTED_OUTPUT "${CMAKE_SOURCE_DIR}/out1.txt")

ADD_CUSTOM_TARGET(t1 COMMAND ${PROJECT_BINARY_DIR}/${EXEC} < ${INPUT})
