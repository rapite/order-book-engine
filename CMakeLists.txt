cmake_minimum_required(VERSION 3.16)

project(OrderBook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(order_lib src/order.cpp src/order_node.cpp src/order_book.cpp) 
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
include(GoogleTest)

# ---- Tests ----
add_executable(test_order tests/test_order.cpp)
target_link_libraries(test_order PRIVATE order_lib GTest::gtest_main)
gtest_discover_tests(test_order)

add_executable(test_order_node tests/test_order_node.cpp)
target_link_libraries(test_order_node PRIVATE order_lib GTest::gtest_main)
gtest_discover_tests(test_order_node)

