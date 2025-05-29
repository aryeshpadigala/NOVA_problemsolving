cmake_minimum_required(VERSION 3.16)
project(AutomobileMaintenance)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

include(FetchContent)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(AutomobileApp
    main.cpp
    Automobile.cpp
    MaintenanceTask.cpp
    MaintenanceLibrary.cpp
)
target_include_directories(AutomobileApp PRIVATE ${CMAKE_SOURCE_DIR})

add_executable(AutomobileTests
    test_main.cpp
    Automobile.cpp
    MaintenanceTask.cpp
    MaintenanceLibrary.cpp
)
target_link_libraries(AutomobileTests gtest_main)
target_include_directories(AutomobileTests PRIVATE ${CMAKE_SOURCE_DIR})
add_test(NAME AutomobileTests COMMAND AutomobileTests)
