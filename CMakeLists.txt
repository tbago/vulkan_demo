cmake_minimum_required(VERSION 3.9)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)

project(vulcan)

include_directories(${PROJECT_SOURCE_DIR})


set(TOY2D_LIBRARY "toy2d")

aux_source_directory("./toy2d" SRC_TOY2D)

message(STATUC ${SRC_TOY2D})

add_library(${TOY2D_LIBRARY} STATIC ${SRC_TOY2D})

find_package(Vulkan REQUIRED)

target_link_libraries(${TOY2D_LIBRARY} PRIVATE Vulkan::Vulkan)

# find_package(PkgConfig REQUIRED)
#
# pkg_check_modules(Vulkan vulkan REQUIRED IMPORTED_TARGET)
#
# target_link_libraries(${TOY2D_LIBRARY} PRIVATE PkgConfig::Vulkan)

add_subdirectory(sandbox)
