cmake_minimum_required(VERSION "3.0.0")

#Set target ouput directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(VALID_BUILD_TYPES "Release" "Debug")

option(BUILD_SHARED_LIBS "True when building a shared library" True)

project("GDL")

# #set CMAKE_BUILD_TYPE default value
# if(NOT CMAKE_CONFIGURATION_TYPES)
#     if("${CMAKE_BUILD_TYPE}" STREQUAL "")
#         set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build configuration" FORCE)
#     endif()
# endif()


# #validate CMAKE_BUILD_TYPE
# if(NOT CMAKE_CONFIGURATION_TYPES)
#     list(FIND VALID_BUILD_TYPES "${CMAKE_BUILD_TYPE}" INDEX)
#     if(${INDEX} MATCHES -1)
#         message(FATAL_ERROR "Invalid build type. Valid types are [${VALID_BUILD_TYPES}]")
#     endif()
# endif()

# if(NOT CMAKE_CONFIGURATION_TYPES)
#     if(DEFINED CMAKE_BUILD_TYPE)
#         set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${VALID_BUILD_TYPES})
#     endif()
# endif()


add_library("${PROJECT_NAME}" include/GDL/Component.hpp)
add_library(GDL::GDL ALIAS "${PROJECT_NAME}")

target_include_directories("${PROJECT_NAME}" PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>" #gdl_export.h
	"$<INSTALL_INTERFACE:include>" #${CMAKE_INSTALL_PREFIX}/include
)

if(NOT BUILD_SHARED_LIBS)
	set(STATIC_POSTFIX "-s")
	set_target_properties("${PROJECT_NAME}" PROPERTIES 
	COMPILE_FLAGS -DFOO_STATIC_DEFINE)
endif()

# #Rename target Foo
# set_target_properties("${PROJECT_NAME}" 
# PROPERTIES
# IMPORTED_LINK_INTERFACE_LIBRARIES       
#         # PROPERTIES
# 	# DEBUG_POSTFIX "${STATIC_POSTFIX}-d" 
# 	# RELEASE_POSTFIX "${STATIC_POSTFIX}"
# 	# MINSIZEREL_POSTFIX "${STATIC_POSTFIX}-mr"
# 	# RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}-rd"
# )

include("GenerateExportHeader")
generate_export_header("${PROJECT_NAME}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/gdl_export.h" DESTINATION "include")


add_subdirectory("example")
add_subdirectory("include")
add_subdirectory("src")