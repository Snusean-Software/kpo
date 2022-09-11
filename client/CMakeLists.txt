set( SOURCES src/main.cpp
             src/client.cpp 
             src/network/impl/unix_sock_session.cpp 
             src/user_io/impl/console_io.cpp )
set( TESTS_SOURCES test/main.cpp )

add_executable( ${CLIENT_TARGET} ${SOURCES} )
target_include_directories( ${CLIENT_TARGET} PUBLIC ${PROJECT_ROOT_DIR}/client/src/network )
target_include_directories( ${CLIENT_TARGET} PUBLIC ${PROJECT_ROOT_DIR}/client/src/user_io )

if( ${CMAKE_BUILD_TESTS} )
     add_executable( ${CLIENT_TESTS_TARGET} ${TESTS_SOURCES} )
     target_include_directories(${CLIENT_TESTS_TARGET} PRIVATE ${PROJECT_ROOT_DIR})
endif()
