cmake_minimum_required(VERSION 3.16)

project(OrderBook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(order_lib src/order.cpp src/order_node.cpp) 
target_include_directories(order_lib PUBLIC include)

# ---- GoogleTest ----
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

# For Windows: prevents overriding parent project’s compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# ---- Tests ----
add_executable(order_tests tests/test_order.cpp)
target_link_libraries(order_tests PRIVATE order_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(order_tests)