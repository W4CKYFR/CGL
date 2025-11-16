cmake_minimum_required(VERSION 3.15)
project(CGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB_RECURSE CGL_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(CGL STATIC ${CGL_SOURCES})

target_include_directories(CGL
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(CGL
  PUBLIC
    glfw
    $<$<TARGET_EXISTS:OpenGL::GL>:OpenGL::GL>
    $<$<NOT:$<TARGET_EXISTS:OpenGL::GL>>:${OPENGL_gl_LIBRARY}>
)

# For MSVC: enable /GL + optimization, drop unreferenced functions
if (MSVC)
  target_compile_options(CGL PRIVATE /GL /O2 /Gy)
  target_link_options(CGL PRIVATE /LTCG /OPT:REF /OPT:ICF)
endif()

# Enable IPO or LTO if the toolchain supports it
set_property(TARGET CGL PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

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
