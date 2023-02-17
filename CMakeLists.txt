cmake_minimum_required(VERSION 3.22.2)  # CMake version check
set(PROJECT_NAME nanotekspice)               # Create project "simple_example"
project(${PROJECT_NAME})               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard
set(CMAKE_CXX_FLAGS_DEBUG)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES
        src/IComponent.hpp
        src/Error.hpp
        src/AComponent.cpp
        src/AComponent.hpp
        src/AShell.hpp
        src/AShell.cpp
        src/AComposedComponent.hpp
        src/AComposedComponent.cpp
        src/Factory.cpp
        src/Factory.hpp
        src/Parser.cpp
        src/Parser.hpp
        src/Handler.cpp
        src/Handler.hpp
        src/components/elementary/And.hpp
        src/components/elementary/And.cpp
        src/components/elementary/Or.hpp
        src/components/elementary/Or.cpp
        src/components/elementary/Xor.hpp
        src/components/elementary/Xor.cpp
        src/components/elementary/Not.hpp
        src/components/elementary/Not.cpp
        src/components/elementary/Nor.hpp
        src/components/elementary/Nor.cpp
        src/components/elementary/Nand.hpp
        src/components/elementary/Nand.cpp
        src/components/elementary/Add.hpp
        src/components/elementary/Add.cpp
        src/components/special/False.hpp
        src/components/special/False.cpp
        src/components/special/True.hpp
        src/components/special/True.cpp
        src/components/special/Clock.hpp
        src/components/special/Clock.cpp
        src/components/special/Input.hpp
        src/components/special/Input.cpp
        src/components/special/Output.cpp
        src/components/special/Output.hpp
        src/components/gate/4001.hpp
        src/components/gate/4001.cpp
        src/components/gate/4011.hpp
        src/components/gate/4011.cpp
        src/components/gate/4030.hpp
        src/components/gate/4030.cpp
        src/components/gate/4069.hpp
        src/components/gate/4069.cpp
        src/components/gate/4071.hpp
        src/components/gate/4071.cpp
        src/components/gate/4081.hpp
        src/components/gate/4081.cpp
        src/components/advanced/4008.hpp
        src/components/advanced/4008.cpp
        src/components/advanced/4512.hpp
        src/components/advanced/4512.cpp
#        tests/File/TestFile.cpp
#        tests/Single/TestSingleAnd.cpp
#        tests/Single/TestSingleOr.cpp
#        tests/Single/TestSingleInputOutput.cpp
#        tests/Single/TestSingleAdd.cpp
#        tests/Single/TestSingleNot.cpp
#        tests/Single/TestSingleClock.cpp
#        tests/Composed/TestSingleXor.cpp
#        tests/Composed/TestComposedNor.cpp
#        tests/Composed/TestComposedNand.cpp
#        tests/Gate/TestGate4001.cpp
#        tests/Gate/TestGate4011.cpp
#        tests/Gate/TestGate4030.cpp
#        tests/Gate/TestGate4069.cpp
#        tests/Gate/TestGate4071.cpp
#        tests/Gate/TestGate4081.cpp
        src/main.cpp
)

set(EXECUTABLE ${PROJECT_NAME})
include_directories(src)
include_directories(src/components)
include_directories(src/components/elementary)
include_directories(src/components/special)
include_directories(src/components/gate)
include_directories(src/components/advanced)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")


# Add the SFML library to the project, uncomment the 2 line under
# if you want to use SFML:
#find_package(SFML 2.5 COMPONENTS Circuitics audio REQUIRED)
#add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE} ${SOURCE_FILES})