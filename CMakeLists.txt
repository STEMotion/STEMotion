cmake_minimum_required(VERSION 3.31)
project(STEMotion)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-4.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(STEMotion main.cpp
    utils/numsize.h
    metrics/metrics.h
    metrics/Distance.cpp
    metrics/Distance.h
    metrics/Force.cpp
    metrics/Force.h
    metrics/Energy.cpp
    metrics/Energy.h
    metrics/Time.cpp
    metrics/Time.h
    metrics/Velocity.cpp
    metrics/Velocity.h
    metrics/BaseQuantity.cpp
    metrics/BaseQuantity.h
    gui/MainWindow.cpp
    gui/MainWindow.h
)

target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})
