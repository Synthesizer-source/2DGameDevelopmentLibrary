include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable("Example" ${SOURCES})
target_link_libraries("Example" PRIVATE GDL::GDL)

