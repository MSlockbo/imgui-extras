cmake_minimum_required(VERSION 3.5)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
set(PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

project(imgui-extras VERSION ${PROJECT_VERSION})

add_library(imgui-extras STATIC imgui_extras.h imgui_extras.cpp)

# DOXYGEN ==============================================================================================================
# https://vicrucann.github.io/tutorials/quick-cmake-doxygen/

find_package(Doxygen)

if(DOXYGEN_FOUND)
	get_filename_component(DOXYGEN_PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
	set(DOXYGEN_CONFIG_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
	set(DOXYGEN_CONFIG_OUT ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)

	configure_file(${DOXYGEN_CONFIG_IN} ${DOXYGEN_CONFIG_OUT} @ONLY)
	message("Doxygen Build Started.")

	if(WIN32)
		add_custom_target(imgui-extras-documentation ALL
				COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIG_OUT}
				COMMAND start firefox "${CMAKE_CURRENT_SOURCE_DIR}/Documentation/html/index.html"
				WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
				COMMENT "Generating Doxygen Documentation"
				VERBATIM)
	else()
		add_custom_target(imgui-extras-documentation ALL
				COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIG_OUT}
				COMMAND firefox "${CMAKE_CURRENT_SOURCE_DIR}/Documentation/html/index.html"
				WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
				COMMENT "Generating Doxygen Documentation"
				VERBATIM)
	endif()
else()
	message("Doxygen not found.")
endif()