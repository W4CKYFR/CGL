cmake_minimum_required(VERSION 3.15)
project(CGL LANGUAGES CXX)

# --- Compiler settings ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Source files ---
file(GLOB_RECURSE CGL_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# --- Create Static Library ---
add_library(CGL STATIC ${CGL_SOURCES})

target_include_directories(CGL
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(CGL
    PUBLIC
        glfw
        OpenGL::GL
)

set_target_properties(CGL PROPERTIES
    OUTPUT_NAME "CGL"
    POSITION_INDEPENDENT_CODE ON
    INTERPROCEDURAL_OPTIMIZATION TRUE  # optional: reduces final lib size
)

# --- Installation ---
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
