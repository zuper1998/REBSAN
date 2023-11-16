//
// Created by andris on 2023.11.16..
//
#include <gtest/gtest.h>
#include "../Algorithms/Utility/file_utility.h"

TEST(BasicFile, TestReadingInData) {

    const std::string test_data = "hG2&l4PqR9sY7uT1xW8i\nfB3*pO7aQ2mZ6cX9jL5k\nsD1#nR8oT4vE7rF3aM6u";

    const std::string data = file_utility::load_from_file("/home/andris/CLionProjects/REBSAN/TestInput/TEST_FILE.txt");

    ASSERT_EQ(test_data,data);

}


TEST(TVGFIle,TestLoad) {
    time_varying_graph tvg= file_utility::load_tvg_from_file("/home/andris/CLionProjects/REBSAN/TestInput/TEST_SAT.sat");


    //std::cout << tvg.export_to_graphviz();






}