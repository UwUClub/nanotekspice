cmake_minimum_required(VERSION 3.13)  # CMake version check
set(PROJECT_NAME nanotekspice)
project(${PROJECT_NAME})               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES
        src/main.cpp
        src/IComponent.hpp
        src/Error.hpp
        src/Graph.cpp
        src/Graph.hpp
        src/AComponent.cpp
        src/AComponent.hpp
        src/Factory.cpp
        src/Factory.hpp
        src/components/And.hpp
        src/components/And.cpp
        src/components/False.hpp
        src/components/False.cpp
        src/components/True.hpp
        src/components/True.cpp
        )
set(EXECUTABLE ${PROJECT_NAME})
include_directories(src/components)
include_directories(src)

# Add the SFML library to the project, uncomment the 2 line under
# if you want to use SFML:
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
#add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE} ${SOURCE_FILES})
