cmake_minimum_required(VERSION 3.14)
project(ArchitectureAndDesignPatterns_HW7_VerticalScalingAndSynchronization)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(
  VerticalScalingAndSynchronization

  source/iCommand.cpp
  source/iCommand.hpp
  source/cException.hpp
  source/cExceptionsHandler.hpp
  source/cExceptionsHandler.cpp
  source/cCommandsDeque.hpp
  source/cCommandsDeque.cpp
  source/VerticalScalingAndSynchronization.hpp
  source/VerticalScalingAndSynchronization.cpp
  
  source/tests/test_iCommand.cpp
  source/tests/test_cCommandsDeque.cpp
  source/tests/test_VerticalScalingAndSynchronization.cpp
  source/tests/test_cExceptionsHandler.cpp
)

target_include_directories(
   VerticalScalingAndSynchronization PRIVATE 
   source
)

target_link_libraries(
  VerticalScalingAndSynchronization
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest GoogleMock)
gtest_discover_tests(VerticalScalingAndSynchronization)