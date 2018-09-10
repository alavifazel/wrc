cmake_minimum_required(VERSION 3.0)

project (wrc)

file(GLOB_RECURSE wrc_SOURCES "src/*.cpp")
file(GLOB_RECURSE wrc_HEADERS "src/*.h")

set (wrc_INCLUDE_DIRS "")
foreach (_headerFile ${wrc_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND wrc_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES wrc_INCLUDE_DIRS)

set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED)

add_executable (wrc ${wrc_SOURCES})
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(wrc ${CURL_LIBRARIES})

target_include_directories(wrc PRIVATE ${wrc_INCLUDE_DIRS})
