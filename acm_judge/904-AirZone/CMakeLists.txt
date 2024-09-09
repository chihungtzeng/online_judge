PROJECT(AriZone)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall -Wextra -Wno-unused-parameter")
ELSE ()
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -Wall -Wextra -Wno-unused-parameter -DONLINE_JUDGE")
ENDIF ()

IF (USE_GPROF)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
ENDIF ()

IF (USE_ASAN)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
ENDIF ()

SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")

SET(EXEC "904_air_zone")
ADD_EXECUTABLE(${EXEC} 904_air_zone.cpp)
SET(INPUT "${CMAKE_SOURCE_DIR}/in.txt")
SET(EXPECTED_OUTPUT "${CMAKE_SOURCE_DIR}/out.txt")
SET(MY_TMP "/tmp")
SET(MY_OUTPUT "${MY_TMP}/my_out")

IF (CMAKE_BUILD_TYPE STREQUAL "Release")
    ADD_CUSTOM_TARGET(t1 
        COMMAND ./${EXEC} < ${INPUT} > ${MY_OUTPUT} 
            && echo "=== diff start" 
            && diff -y --suppress-common-lines -W 80 ${MY_OUTPUT} ${EXPECTED_OUTPUT}
            )
ENDIF ()

IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
    ADD_CUSTOM_TARGET(t1 COMMAND ${EXEC})
ENDIF ()
