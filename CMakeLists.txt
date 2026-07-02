cmake_minimum_required(VERSION 3.31)

project(
    ignis
    LANGUAGES C CXX
)

if(WIN32)
    set(PLATFORM_SRC src/platform/windows.cpp)
elseif(APPLE)
    set(PLATFORM_SRC src/platform/mac.cpp)
elseif(UNIX)
    set(PLATFORM_SRC src/platform/linux.cpp)
endif()

add_executable(ignis src/main.cpp ${PLATFORM_SRC})

set_target_properties(ignis PROPERTIES CXX_STANDARD 23)
target_include_directories(ignis PUBLIC src)