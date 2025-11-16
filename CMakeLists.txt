cmake_minimum_required(VERSION 3.15)
project(CGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find dependencies
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

# Source files
file(GLOB_RECURSE CGL_SOURCES
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Build static library
add_library(CGL STATIC ${CGL_SOURCES})

# Include headers
target_include_directories(CGL
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Link libraries
if (TARGET OpenGL::GL)
  target_link_libraries(CGL PUBLIC glfw OpenGL::GL)
else()
  target_link_libraries(CGL PUBLIC glfw ${OPENGL_gl_LIBRARY})
endif()

# Enable interprocedural optimization / LTO if supported
set_property(TARGET CGL PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

# Installation
include(GNUInstallDirs)

install(TARGETS CGL
  EXPORT CGLTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT CGLTargets
  FILE CGLTargets.cmake
  NAMESPACE CGL::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CGL
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/CGLConfigVersion.cmake
  VERSION 1.0.0
  COMPATIBILITY SameMajorVersion
)

install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/CGLConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/CGLConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CGL
)
