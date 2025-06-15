cmake_minimum_required(VERSION 3.31)
project(STEMotion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

find_package(PkgConfig)
find_package(epoxy REQUIRED)

pkg_check_modules(GTKMM gtkmm-4.0)
add_subdirectory(LibSTEMotion)
include_directories(LibSTEMotion/include)
include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(vendor)
include_directories(${epoxy_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

if (UNIX)
  set(PLUGIN_LOADER plugin/platform/unix.cpp)
elseif(WIN32)
  set(PLUGIN_LOADER plugin/platform/windows.h)
else()
  message(FATAL_ERROR "Unsupported platform")
endif()

add_executable(STEMotion main.cpp
    gui/MainWindow.cpp
    gui/MainWindow.h
    gui/SimulationWindow.cpp
    gui/SimulationWindow.h
    gui/simulation_window/SimulationView.cpp
    gui/simulation_window/SimulationView.h
    renderer/Renderer.cpp
    renderer/Renderer.h
    gui/simulation_window/ParametersView.cpp
    gui/simulation_window/ParametersView.h
    gui/simulation_window/PredictionsView.cpp
    gui/simulation_window/PredictionsView.h
    plugin/SimulationPlugin.cpp
    plugin/SimulationPlugin.h
    plugin/platform/unix.cpp
    plugin/platform/windows.cpp
    plugin/platform/PlatformInterface.h
    ${PLUGIN_LOADER}
)

target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES} ${epoxy_LIBRARIES} LibSTEMotion)
