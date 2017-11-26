aux_source_directory(. SCENE_SRCS)
add_library(scene ${SCENE_SRCS})
target_link_libraries(scene light object util)

add_executable(debug ${SCENE_SRCS})
target_link_libraries(debug scene)
