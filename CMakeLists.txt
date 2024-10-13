cmake_minimum_required(VERSION 3.12)

set(APPLICATION allocator_and_map)

set(LIBLARY ${APPLICATION}_library)
set(LIBLARY_FOLDER ${APPLICATION}_lib_folder)

file(GLOB_RECURSE LIB_SOURCES ${LIBLARY_FOLDER}/src/cpp/*.cpp)
file(GLOB_RECURSE LIB_HEADERS ${LIBLARY_FOLDER}/src/include/*.h)

# There is a function for colling from application's main 
set(LIBLARY_MAIN ${APPLICATION}_library_main)
file(GLOB_RECURSE LIBRARY_MAIN_FILE ${APPLICATION}_lib_main.cpp)


set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(${APPLICATION} VERSION ${PROJECT_VESRION})

option(WITH_BOOST_TEST "Whether to build Boost test" ON)
option(WITH_GOOGLE_TEST "Whether to build Google test" ON)

configure_file(version.h.in version.h)

add_executable(${APPLICATION} main.cpp)


add_library(${LIBLARY} ${LIB_SOURCES} lib.cpp)
target_include_directories(${LIBLARY} PUBLIC ${LIBLARY_FOLDER}/src/include)

add_library(${LIBLARY_MAIN} ${LIB_SOURCES} lib.cpp ${LIBRARY_MAIN_FILE})
target_include_directories(${LIBLARY_MAIN} PUBLIC ${LIBLARY_FOLDER}/src/include)


set_target_properties(${APPLICATION} ${LIBLARY} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(${APPLICATION} ${LIBLARY} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


target_include_directories(${LIBLARY_MAIN}
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(${APPLICATION} PRIVATE
${LIBLARY_MAIN}
)

if(WITH_BOOST_TEST)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    add_executable(test_version test_version.cpp)

    set_target_properties(test_version PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
    )

    set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
    )

    target_link_libraries(test_version
        ${Boost_LIBRARIES}
        ${LIBLARY}
    )
endif()

if (MSVC)
    target_compile_options(${APPLICATION} PRIVATE
        /W4
    )
    target_compile_options(${LIBLARY} PRIVATE
        /W4
    )
    if(WITH_BOOST_TEST)
        target_compile_options(test_version PRIVATE
            /W4
        )
    endif()
else ()
    target_compile_options(${APPLICATION} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(${LIBLARY} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    if(WITH_BOOST_TEST)
        target_compile_options(test_version PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS ${APPLICATION} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_BOOST_TEST)
    enable_testing()
    add_test(test_version test_version)
endif()

if(WITH_GOOGLE_TEST)
# Настройка Google Test (предполагается, что у вас установлен gtest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


#Add Tests
set(TEST_APPLICATION ${APPLICATION}_tests)
file(GLOB TEST_SOURCES ${LIBLARY_FOLDER}/tests/*.cpp)
file(GLOB TEST_APPLICATION_MAIN_FILE ${LIBLARY_FOLDER}/tests/tests_main.cpp)

set(TEST_LIB_NAME ${APPLICATION}_tests_lib)

add_executable(${TEST_APPLICATION} ${TEST_APPLICATION_MAIN_FILE})
add_library(${APPLICATION}_tests_lib ${TEST_SOURCES})

target_link_libraries(${TEST_APPLICATION} ${LIBLARY} ${GTEST_LIBRARIES} ${TEST_LIB_NAME})

# Регистрация тестов
add_test(NAME IPLibTests COMMAND ${TEST_APPLICATION})

#target_sources(${LIBLARY} PRIVATE ${LIB_SOURCES} ${LIB_HEADERS})

set_target_properties(${APPLICATION} ${TESTS} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
endif()

