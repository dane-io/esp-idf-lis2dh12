cmake_minimum_required(VERSION 3.16)

# Use the driver directly from this repository's root.
set(EXTRA_COMPONENT_DIRS "${CMAKE_CURRENT_LIST_DIR}/..")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(lis2dh12_basic_read)
