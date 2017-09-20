#cmake_minimum_required(VERSION 3.6)
set(LIBDIR ${CMAKE_SOURCE_DIR}/demo)
include_directories(${LIBDIR}/include)
add_library(libPro1
            SHARED
            IMPORTED
)
set_target_properties(
            libPro1
            PROPERTIES IMPORTED_LOCATION
            ${LIBDIR}/lib/${ANDROID_ABI}/libPro1.a
)
add_library(libPro2
            SHARED
            IMPORTED
)
set_target_properties(
            libPro2
            PROPERTIES IMPORTED_LOCATION
            ${LIBDIR}/lib/${ANDROID_ABI}/libPro2.a
)
find_library(
    log-lib
    log
)
file(GLOB SRCS "${LIBDIR}/src/*.cpp")
add_library(
    demolib
    SHARED
    ${SRCS}
)
target_link_libraries(
      demolib
      ${log-lib}
)
target_link_libraries(
   demolib
    "-Wl,--whole-archive"
    libPro1
    "-Wl,--no-whole-archive"
)
target_link_libraries(
    demolib
    "-Wl,--whole-archive"
    libPro2
    "-Wl,--no-whole-archive"
)