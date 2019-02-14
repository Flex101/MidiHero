cmake_minimum_required(VERSION 3.2)

project(MidiHero VERSION 1.0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# -----------------------------------------------------------------------------
# External libraries

# Find the QtWidgets library
find_package(Qt5Core)
find_package(Qt5Widgets CONFIG REQUIRED)

# -----------------------------------------------------------------------------
# Header files

set(${PROJECT_NAME}_HDRS
	includes/MainWindow.h
	includes/Controls/Image.h
)

# -----------------------------------------------------------------------------
# Source files

set(${PROJECT_NAME}_SRCS
	src/main.cpp
	src/MainWindow.cpp
	src/Controls/Image.cpp
)

# -----------------------------------------------------------------------------
# Resources

qt5_add_resources(${PROJECT_NAME}_RES
	"resource.qrc"
)

# -----------------------------------------------------------------------------
# Libraries to link

set(${PROJECT_NAME}_LIBRARIES
	Qt5::Core
	Qt5::Widgets
)

set(${PROJECT_NAME}_INCLUDE_DIRS
	PUBLIC
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/includes>
)

# ----------------------------------------------------------------------------
# Compile Main

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS} ${${PROJECT_NAME}_HDRS} ${${PROJECT_NAME}_RES})
target_include_directories(${PROJECT_NAME} ${${PROJECT_NAME}_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${${PROJECT_NAME}_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	OUTPUT_NAME ${PROJECT_NAME}
)
