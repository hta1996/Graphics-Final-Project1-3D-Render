#add_subdirectory(raytracer)

aux_source_directory(. ENGINE_SRCS)
aux_source_directory(raytracer RAY_TRACER_SRCS)
#aux_source_directory(photonmapper PHOTON_MAPPER_SRCS)
#aux_source_directory(ppm PPM_SRCS)
#aux_source_directory(sppm SPPM_SRCS)

#add_library(engine ${ENGINE_SRCS} ${RAY_TRACER_SRCS} ${PHOTON_MAPPER_SRCS} ${PPM_SRCS} ${SPPM_SRCS})
add_library(engine ${ENGINE_SRCS} ${RAY_TRACER_SRCS})
target_link_libraries(engine scene)
#target_link_libraries(engine scene pthread)


#add_executable(debug ${UTIL_SRCS})
