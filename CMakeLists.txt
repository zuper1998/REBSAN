cmake_minimum_required(VERSION 3.27)
project(REBSAN)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ")

include_directories("/home/narcano/llvm-project/build/include/x86_64-linux-gnu/c++/v1")


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
        Algorithms/Utility/SearchInterval.h
        Algorithms/Utility/file_utility.h
        Algorithms/Utility/tvg_path.cpp
        Algorithms/Utility/tvg_path.h
)



enable_testing()

add_executable(
        GraphTest
        Tests/interval_test.cc
        Tests/graph_test.cc
        Algorithms/Utility/visibility_interval.cpp
        Algorithms/Utility/visiblity_interval.h
        Algorithms/Graph/time_varying_graph.cpp
        Algorithms/Graph/time_varying_graph.h
        Algorithms/Graph/Node.cpp
        Algorithms/Graph/Node.h
        Tests/NodeTest.h
        Algorithms/Utility/SearchInterval.h
        Tests/GraphTest.h
        Tests/test_file_load.cc
        Algorithms/Utility/file_utility.h
        Algorithms/Utility/tvg_path.cpp
        Algorithms/Utility/tvg_path.h
)



target_link_libraries(
        GraphTest
        GTest::gtest_main
)



include(GoogleTest)
gtest_discover_tests(GraphTest)
