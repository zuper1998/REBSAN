cmake_minimum_required(VERSION 3.27)
project(REBSAN)

set(CMAKE_CXX_STANDARD 23)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(REBSAN main.cpp
        Algorithms/Utility/visibility_interval.cpp
        Algorithms/Utility/visiblity_interval.h
        Algorithms/Graph/time_varying_graph.cpp
        Algorithms/Graph/time_varying_graph.h
        Algorithms/Graph/Node.cpp
        Algorithms/Graph/Node.h
)


enable_testing()

add_executable(
        hello_test
        Tests/interva_test.cc
        Algorithms/Utility/visibility_interval.cpp
        Algorithms/Utility/visiblity_interval.h
        Tests/graph_test.cc
        Algorithms/Graph/time_varying_graph.cpp
        Algorithms/Graph/time_varying_graph.h
        Algorithms/Graph/Node.cpp
        Algorithms/Graph/Node.h
)
target_link_libraries(
        hello_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
