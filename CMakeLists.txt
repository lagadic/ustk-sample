project(ustk_sample)

cmake_minimum_required(VERSION 3.0)

find_package(VISP REQUIRED)
if(VISP_FOUND)
  include_directories(${VISP_INCLUDE_DIRS})
  include_directories(${USTK_INCLUDE_DIR})
endif()

#--------------------------------------------------------------------
# By default set release configuration
#--------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None Debug Release" FORCE)
endif()

add_executable(usImagePreScan2DSample usImagePreScan2DSample.cpp)
add_executable(usImagePostScan2DSample usImagePostScan2DSample.cpp)
add_executable(usImageRF2DSample usImageRF2DSample.cpp)
add_executable(usImagePreScan3DSample usImagePreScan3DSample.cpp)
add_executable(usImagePostScan3DSample usImagePostScan3DSample.cpp)
add_executable(usImageRF3DSample usImageRF3DSample.cpp)
add_executable(usPostScanToPreScan2DConverterSample usPostScanToPreScan2DConverterSample.cpp)
add_executable(usPreScanToPostScan2DConverterSample usPreScanToPostScan2DConverterSample.cpp)
add_executable(usPreScanToPostScan3DConverterSample usPreScanToPostScan3DConverterSample.cpp)
add_executable(usRFToPostScan2DConverterSample usRFToPostScan2DConverterSample.cpp)
add_executable(usRFToPostScan3DConverterSample usRFToPostScan3DConverterSample.cpp)
add_executable(usRFToPreScan2DConverterSample usRFToPreScan2DConverterSample.cpp)
add_executable(usRFToPreScan3DConverterSample usRFToPreScan3DConverterSample.cpp)

target_link_libraries(usImagePreScan2DSample visp_core visp_io visp_ustk_core)
target_link_libraries(usImagePostScan2DSample visp_core visp_io visp_ustk_core)
target_link_libraries(usImageRF2DSample visp_core visp_io visp_ustk_core)
target_link_libraries(usImagePreScan3DSample visp_core visp_io visp_ustk_core)
target_link_libraries(usImagePostScan3DSample visp_core visp_io visp_ustk_core)
target_link_libraries(usImageRF3DSample visp_core visp_io visp_ustk_core)
target_link_libraries(usPostScanToPreScan2DConverterSample visp_core visp_io visp_ustk_core)
target_link_libraries(usPreScanToPostScan2DConverterSample visp_core visp_io visp_ustk_core)
target_link_libraries(usPreScanToPostScan3DConverterSample visp_core visp_io visp_ustk_core)
target_link_libraries(usRFToPostScan2DConverterSample visp_core visp_io visp_ustk_core)
target_link_libraries(usRFToPostScan3DConverterSample visp_core visp_io visp_ustk_core)
target_link_libraries(usRFToPreScan2DConverterSample visp_core visp_io visp_ustk_core)
target_link_libraries(usRFToPreScan3DConverterSample visp_core visp_io visp_ustk_core)
