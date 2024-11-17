cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

set (APPLICATION MyApp) 
set (APPLICATION_cli MyApp_cli) 

project(${APPLICATION} VERSION ${PROJECT_VESRION})


configure_file(version.h.in version.h)

add_executable(${APPLICATION_cli} main.cpp lib.cpp)

set_target_properties(${APPLICATION_cli} PROPERTIES
    CXX_STANDARD 20    
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(${APPLICATION_cli} PRIVATE
        /W4
    )
    target_compile_options(hellow${APPLICATION_cli} PRIVATE
        /W4
    )
else ()
    target_compile_options(${APPLICATION_cli} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(${APPLICATION_cli} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS ${APPLICATION_cli} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

