cmake_minimum_required(VERSION 3.31)
project(LibSTEMotion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ..)

include_directories(include)

add_library(
    LibSTEMotion

    include/LibSTEMotion/utils/numsize.h
    include/LibSTEMotion/metrics/metrics.h
    src/metrics/Distance.cpp
    include/LibSTEMotion/metrics/Distance.h
    src/metrics/Force.cpp
    include/LibSTEMotion/metrics/Force.h
    src/metrics/Energy.cpp
    include/LibSTEMotion/metrics/Energy.h
    src/metrics/Time.cpp
    include/LibSTEMotion/metrics/Time.h
    src/metrics/Velocity.cpp
    include/LibSTEMotion/metrics/Velocity.h
    src/metrics/BaseQuantity.cpp
    include/LibSTEMotion/metrics/BaseQuantity.h
    include/LibSTEMotion/plugin.h
    include/LibSTEMotion/renderer/DrawQueue.h
    src/simulation/SimulationParams.cpp
    include/LibSTEMotion/SimulationParams.h
    include/LibSTEMotion/STEMotion.h
    src/renderer/DrawQueue.cpp
    src/metrics/Mass.cpp
    include/LibSTEMotion/metrics/Mass.h
    src/metrics/Angle.cpp
    include/LibSTEMotion/metrics/Angle.h
    src/simulation/SimulationOutput.cpp
    include/LibSTEMotion/SimulationOutput.h
        include/LibSTEMotion/renderer/Object.h
)