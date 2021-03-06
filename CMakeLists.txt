cmake_minimum_required(VERSION 2.8) 

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.abc
set(PROJECT_NAME Lambada)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Define project sources and includes
#----------------------------------------------------------------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/opengl_IMGUI/dependencies)
set(SRC ${PROJECT_SOURCE_DIR}/opengl_IMGUI/src)
include_directories(${COMMON_INCLUDES})

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/opengl_IMGUI/src/*.cpp ${PROJECT_SOURCE_DIR}/opengl_IMGUI/src/*.c)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/opengl_IMGUI/test/*.cpp)
#list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/opengl_IMGUI/src/main.cpp)

set(CMAKE_CXX_STANDARD 11)

################################
# Normal Libraries & Executables
################################

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
	
add_subdirectory(${PROJECT_SOURCE_DIR}/opengl_IMGUI/linux/glfw-master)


add_executable(Lambada ${SRC}/main.cpp ${SRC}/glad.c opengl_IMGUI/src/imgui.cpp ${SRC}/imgui_demo.cpp ${SRC}/imgui_impl_glfw.cpp ${SRC}/imgui_impl_opengl3.cpp ${SRC}/imgui_widgets.cpp ${SRC}/imgui_draw.cpp)

# Key idea: SEPARATE OUT your main() function into its own file so it can be its
# own executable. Separating out main() means you can add this library to be
# used elsewhere (e.g linking to the test executable).



target_link_libraries(Lambada glfw)

################################
# Testing
################################

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(BUILD_TESTS "Build all tests." OFF) # Makes boolean 'test' available.

if (BUILD_TESTS)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(opengl_IMGUI/linux/ext/gtest-1.8.0)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/gTest)

  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests ${TEST_SRC_FILES})

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # Extra linking for the project.
  

	

   target_link_libraries(runUnitTests glfw)


  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(UnitTests runUnitTests)

  set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.travis/cmake)

  if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage runUnitTests coverage)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
  endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"

endif()
