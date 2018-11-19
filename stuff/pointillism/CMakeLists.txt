project( pointillism )
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )

find_package( OpenMP REQUIRED )
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

include_directories( POINTILLISM ${CMAKE_CURRENT_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
list(REMOVE_ITEM SRC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
add_definitions(-std=c++14)

add_executable(pointillism "./src/main.cpp" ${SRC_LIST} ${POINTILLISM})
add_executable(test_pointillism "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp" ${SRC_LIST} ${POINTILLISM})

target_link_libraries(pointillism pthread)
target_link_libraries(test_pointillism pthread)
