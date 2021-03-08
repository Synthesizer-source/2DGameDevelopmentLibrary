set(FILES "")
set(SUBDIRECTORIES "GDL")
set(RELATIVE_PATH "src")

#Add all subdirectories 
foreach(VAR ${SUBDIRECTORIES})
	add_subdirectory(${VAR})
endforeach()

if(FILES)
	#Add source files to target
	target_sources("${PROJECT_NAME}" PRIVATE ${FILES})
	
	#Install our source files
	install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif()

# get_target_property(GDL_SOURCE_DIR GDL SOURCE_DIR)


# message(${GDL_SOURCE_DIR})