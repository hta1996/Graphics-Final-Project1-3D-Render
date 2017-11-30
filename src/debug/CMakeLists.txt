add_sources(debug_scene.cpp)
add_executable(debug_scene debug_scene.cpp)
target_link_libraries(debug_scene scene yaml-cpp utility)
#add_library(debug_utilcc yaml-cpp utility)


add_sources(debug_util.cpp)
add_executable(debug_util debug_util.cpp)
target_link_libraries(debug_util utility  yaml-cpp)
 