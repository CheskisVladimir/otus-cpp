cmake_minimum_required(VERSION 3.12)
project(allocator_and_map)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

# Укажите стандарты C++ (например, C++11)
set(CMAKE_CXX_STANDARD 17)

# Параметры для библиотеки
file(GLOB_RECURSE LIB_SOURCES src/cpp/*.cpp)
file(GLOB_RECURSE LIB_HEADERS src/include/*.h)

add_library(allocator_and_map_library ${LIB_SOURCES})
target_include_directories(allocator_and_map_library PUBLIC src/include)

# Основная программа
add_executable(allocator_and_map app/main.cpp)
target_link_libraries(allocator_and_map allocator_and_map_library)

# Настройка Google Test (предполагается, что у вас установлен gtest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавление тестов
file(GLOB TEST_SOURCES tests/*.cpp)
add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests allocator_and_map_library ${GTEST_LIBRARIES})

# Регистрация тестов
add_test(NAME allocator_and_map_tests COMMAND runTests)

# Автоматическое добавление файлов в библиотеку
target_sources(allocator_and_map_library PRIVATE ${LIB_SOURCES} ${LIB_HEADERS})

set_target_properties(allocator_and_map runTests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(allocator_and_map_library PRIVATE
-Wall -Wextra -pedantic -Werror
)

target_compile_options(allocator_and_map_library PRIVATE
-Wall -Wextra -pedantic -Werror
)

install(TARGETS allocator_and_map RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
