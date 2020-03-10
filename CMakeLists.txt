cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(collection VERSION 1.0.0 LANGUAGES C)
set(PROEJCT_DESCRIPTION "Collection test applications")

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fuse-ld=gold -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-sanitize=alignment -static-libasan")
endif()

# Build settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

# Integrate with Conan if possible
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Platform Detection
add_definitions(-DARCH_WORDSIZE=${CMAKE_SIZEOF_VOID_P})

# Build settings
include_directories(BEFORE include)
set(sources
	src/queue.c
	main.c
	)

add_library(objs OBJECT ${sources})
set_property(TARGET objs PROPERTY POSITION_INDEPENDENT_CODE 1)

# add_library(collection $<TARGET_OBJECTS:objs>)
add_executable(tester main.c src/queue.c)
target_link_libraries(tester "${CONAN_LIBS}")
