cmake_minimum_required(VERSION 3.0)

project (wrc)

file(GLOB_RECURSE wrc_SOURCES "src/*.cpp")
file(GLOB_RECURSE wrc_HEADERS "src/*.h")

set (CMAKE_CXX_STANDARD 17)

set (wrc_INCLUDE_DIRS "")
foreach (_headerFile ${wrc_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND wrc_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES wrc_INCLUDE_DIRS)

set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.66 REQUIRED COMPONENTS system program_options) 
find_package (Threads)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})


add_executable (wrc ${wrc_SOURCES})
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(wrc ${CURL_LIBRARIES})
TARGET_LINK_LIBRARIES(wrc ${Boost_LIBRARIES})

target_include_directories(wrc PRIVATE ${wrc_INCLUDE_DIRS})
