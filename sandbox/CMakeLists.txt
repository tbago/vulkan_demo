
add_executable(sandbox)

aux_source_directory("./" SANDBOX_SRC)

target_sources(sandbox PRIVATE ${SANDBOX_SRC})

find_package(SDL2 REQUIRED)

target_link_libraries(sandbox PRIVATE toy2d SDL2::SDL2)
