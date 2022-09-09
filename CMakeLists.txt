cmake_minimum_required( VERSION 3.10 )
project( kpo-prog )

set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread" )
set( PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR} )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT_DIR}/bin )

set( CLIENT_TARGET client )
set( SERVER_TARGET server )

if( ${CMAKE_BUILD_TESTS} )
     set( CLIENT_TESTS_TARGET client_tests )
     set( SERVER_TESTS_TARGET server_tests )
endif()

add_subdirectory( client )
add_subdirectory( server )