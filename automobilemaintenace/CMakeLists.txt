# CMakeLists.txt
# Build system for Automobile Maintenance Project with Google Test

cmake_minimum_required(VERSION 3.16)
project(AutomobileMaintenance)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)

# Enable test system
enable_testing()

# Fetch Google Test framework automatically
include(FetchContent)

# Handle CMP0135 warning
if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)


# Define main app
add_executable(AutomobileApp
    main.cpp
    Automobile.cpp
    MaintenanceTask.cpp
    MaintenanceLibrary.cpp
)
target_include_directories(AutomobileApp PRIVATE ${CMAKE_SOURCE_DIR})

# Define test app
add_executable(AutomobileTests
    test_main.cpp
    Automobile.cpp
    MaintenanceTask.cpp
    MaintenanceLibrary.cpp
)
target_link_libraries(AutomobileTests gtest_main)
target_include_directories(AutomobileTests PRIVATE ${CMAKE_SOURCE_DIR})
add_test(NAME AutomobileTests COMMAND AutomobileTests)
