cmake_minimum_required(VERSION 3.10)
project(ip_filter)

# Укажите стандарты C++ (например, C++11)
set(CMAKE_CXX_STANDARD 17)

# Параметры для библиотеки
file(GLOB_RECURSE LIB_SOURCES src/cpp/*.cpp)
file(GLOB_RECURSE LIB_HEADERS src/include/*.h)

add_library(ip_library ${LIB_SOURCES})
target_include_directories(ip_library PUBLIC src/include)

# Основная программа
add_executable(ip_filter app/main.cpp)
target_link_libraries(ip_filter ip_library)

# Настройка Google Test (предполагается, что у вас установлен gtest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавление тестов
file(GLOB TEST_SOURCES tests/*.cpp)
add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests ip_library ${GTEST_LIBRARIES})

# Регистрация тестов
add_test(NAME IPLibTests COMMAND runTests)

# Автоматическое добавление файлов в библиотеку
target_sources(ip_library PRIVATE ${LIB_SOURCES} ${LIB_HEADERS})
