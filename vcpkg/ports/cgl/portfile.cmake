vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO W4CKYFR/CGL
    REF v.0.0.1
)

vcpkg_cmake_configure(
    SOURCE_PATH ${SOURCE_PATH}
    PREFER_NINJA
)

vcpkg_cmake_build()

vcpkg_cmake_install()
