set( SOURCES src/main.cpp )
set( TESTS_SOURCES test/main.cpp )

add_executable( ${SERVER_TARGET} ${SOURCES} )

if( ${CMAKE_BUILD_TESTS} )
     add_executable( ${SERVER_TESTS_TARGET} ${TESTS_SOURCES} )
     target_include_directories(${SERVER_TESTS_TARGET} PRIVATE ${PROJECT_ROOT_DIR})
endif()
