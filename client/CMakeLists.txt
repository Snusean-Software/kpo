set( SOURCES src/main.cpp )
set( TESTS_SOURCES test/main.cpp )

add_executable( ${CLIENT_TARGET} ${SOURCES} )

if( ${CMAKE_BUILD_TESTS} )
     add_executable( ${CLIENT_TESTS_TARGET} ${TESTS_SOURCES} )
     target_include_directories(${CLIENT_TESTS_TARGET} PRIVATE ${PROJECT_ROOT_DIR})
endif()
