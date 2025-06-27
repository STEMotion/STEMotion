cmake_minimum_required(VERSION 3.6)
project(STEMotion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

find_package(PkgConfig)
find_package(epoxy REQUIRED)
find_package(Freetype REQUIRED)

include(FetchContent)

FetchContent_Declare(
        glm
        GIT_REPOSITORY	https://github.com/g-truc/glm.git
        GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

pkg_check_modules(GTKMM gtkmm-4.0)
add_subdirectory(LibSTEMotion)
include_directories(LibSTEMotion/include)
include_directories(${GTKMM_INCLUDE_DIRS})
include_directories(vendor)
include_directories(${epoxy_INCLUDE_DIRS})
include_directories(${FREETYPE_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

if (UNIX)
  set(PLUGIN_LOADER plugin/platform/unix.cpp)
elseif(WIN32)
  set(PLUGIN_LOADER plugin/platform/windows.h
          renderer/objects/object.h)
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
        renderer/Shader.cpp
        renderer/Shader.h
        renderer/objects/circle.cpp
        renderer/objects/triangle.cpp
        renderer/objects/rectangle.cpp
        renderer/objects/line.cpp
        renderer/typeface/Typeface.cpp
        renderer/typeface/Typeface.h
        renderer/font/font_bold.h
        renderer/font/font_italic.h
        renderer/font/font_regular.h
)

target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES} ${epoxy_LIBRARIES} ${FREETYPE_LIBRARIES} LibSTEMotion glm::glm)
