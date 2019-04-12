cmake_minimum_required(VERSION 2.8.12)

set(TARGET_NAME crtp_performance)

project(${TARGET_NAME})

# Check and add the C++ version
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++20" COMPILER_SUPPORTS_CXX20)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX20)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
elseif(COMPILER_SUPPORTS_CXX17)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(COMPILER_SUPPORTS_CXX14)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++0x support. Please use a different C++ compiler.")
endif()

# Set the source files.
set(SOURCES
  main.cpp
  dynamic_interface.cpp
  crtp_interface.cpp)

# Create the executable builded with the source files.
add_executable(${TARGET_NAME} ${SOURCES})

# Set warning level
if(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE -Wall -pedantic -Werror)
endif(MSVC)

# Set the debug or relese mode.
if (CMAKE_BUILD_TYPE MATCHES Debug)
  # Debug level
  target_compile_options(${TARGET_NAME} PRIVATE -g)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
  # Optimization level
  target_compile_options(${TARGET_NAME} PRIVATE -O2)
else ()
  message( FATAL_ERROR "Set the build type with -DCMAKE_BUILD_TYPE=<type>")
endif()

# Bring the headers into the project.
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR})

# Add the libraries to the executable.
target_link_libraries(${TARGET_NAME})