cmake_minimum_required(VERSION 3.0)
project(2048-game)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Define the source files for your project
file(GLOB SOURCES "src/*.cpp")

# Set the path to SFML library and include directories
if (APPLE) 
    set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1")
elseif (WIN32)
    set(SFML_DIR "[path to SFML library in your windows machine]")
endif()

# Find SFML components
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# Add the source files to the executable and link SFML libraries
add_executable(game ${SOURCES})
target_link_libraries(game sfml-graphics sfml-window sfml-system)

# Specify the include directories for SFML headers
target_include_directories(game PRIVATE ${SFML_INCLUDE_DIR})