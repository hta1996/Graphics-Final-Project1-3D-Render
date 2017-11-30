aux_source_directory(. UTILITY_SRCS)
#add_library(utility ${UTILITY_SRCS})
add_library(utility ${UTILITY_SRCS})
target_link_libraries(utility yaml-cpp)