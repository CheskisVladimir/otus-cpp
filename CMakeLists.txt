cmake_minimum_required(VERSION 3.12)
project(ip_filter)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

# Укажите стандарты C++ (например, C++11)
set(CMAKE_CXX_STANDARD 17)

# Параметры для библиотеки
file(GLOB_RECURSE LIB_SOURCES ip_filter/src/cpp/*.cpp)
file(GLOB_RECURSE LIB_HEADERS ip_filter/src/include/*.h)

add_library(ip_library ${LIB_SOURCES} lib.cpp)
target_include_directories(ip_library PUBLIC ip_filter/src/include)

# Основная программа
add_executable(ip_filter_cli ip_filter/app/main.cpp)
target_link_libraries(ip_filter_cli ip_library)

# Настройка Google Test (предполагается, что у вас установлен gtest)
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Добавление тестов
file(GLOB TEST_SOURCES ip_filter/tests/*.cpp)
add_executable(ip_filter_tests ${TEST_SOURCES})
target_link_libraries(ip_filter_tests ip_library ${GTEST_LIBRARIES} pthread)

# Регистрация тестов
add_test(NAME IPLibTests COMMAND ip_filter_tests)

# Автоматическое добавление файлов в библиотеку
target_sources(ip_library PRIVATE ${LIB_SOURCES} ${LIB_HEADERS})

set_target_properties(ip_filter_cli ip_filter_tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(ip_library PRIVATE
-Wall -Wextra -pedantic -Werror
)

target_compile_options(ip_library PRIVATE
-Wall -Wextra -pedantic -Werror
)

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
