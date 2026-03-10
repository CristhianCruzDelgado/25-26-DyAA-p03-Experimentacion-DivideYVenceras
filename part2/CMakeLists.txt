cmake_minimum_required(VERSION 3.10)
project(EmployeeScheduling)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Source files
set(SOURCES
    src/main.cc
    src/divide-conquer.cc
    src/employees-days-shifts.cc
    src/loader-employee-day-shift.cc
    src/plan-employees.cc
    src/saver-schedule.cc
    src/schedule.cc
)

# Executable
add_executable(planificar-empleados ${SOURCES})

# Link libraries
add_subdirectory(json)
target_link_libraries(planificar-empleados PRIVATE nlohmann_json::nlohmann_json)

# Instructions
# 1. mkdir build
# 2. cd build
# 3. cmake ..
# 4. make
# 5. ./planificar-empleados --help