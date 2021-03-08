cmake_minimum_required(VERSION "3.0.0")

#Set target ouput directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(VALID_BUILD_TYPES "Release" "Debug")

option(BUILD_SHARED_LIBS "True when building a shared library" True)

project("GDL")

add_library("${PROJECT_NAME}" "")
add_library(GDL::GDL ALIAS "${PROJECT_NAME}")

#SFMLConfig.make directory
set(SFML_DIR "./SFML-2.5.1/lib/cmake/SFML")
find_package(SFML REQUIRED graphics audio)


target_include_directories("${PROJECT_NAME}" PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>" #gdl_export.h
	"$<INSTALL_INTERFACE:include>" #${CMAKE_INSTALL_PREFIX}/include
	"$<BUILD_INTERFACE:${SFML_INCLUDE_DIRS}>"
)

target_link_libraries(GDL PUBLIC sfml-graphics sfml-audio sfml-window sfml-system)

if(NOT BUILD_SHARED_LIBS)
	set(STATIC_POSTFIX "-s")
	set_target_properties("${PROJECT_NAME}" PROPERTIES 
	COMPILE_FLAGS -DFOO_STATIC_DEFINE)
endif()

# set_target_properties(${PROJECT_NAME} PROPERTIES SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
include("GenerateExportHeader")
generate_export_header("${PROJECT_NAME}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/gdl_export.h" DESTINATION "include")
# add_definitions( -DGDL_DIR="${GDL_SOURCE_DIR}")
ADD_DEFINITIONS( -DGDL_DIR=\"${GDL_SOURCE_DIR}\" )
# target_compile_definitions("GDL" PUBLIC FOO=1)
add_subdirectory("example")
add_subdirectory("include")
add_subdirectory("src")