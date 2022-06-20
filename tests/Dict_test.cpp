#include <chrono>
#include <fstream>
#include "gtest/gtest.h"
#include "../service/Dict.h"


// do not really want to make magic with relative paths and glob
#define huge_path "D:\\CLionProjects\\Avito_HW\\files\\huge.txt"
#define example_path "D:\\CLionProjects\\Avito_HW\\files\\out_huge.txt"


TEST (Dict, time_test)
{
    auto start_time =  std::chrono::high_resolution_clock::now();

    auto d = Dict(huge_path);
    d.load_file();
    d.calculate_word_freq();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto search_time = end_time - start_time;
    EXPECT_TRUE((6000 > std::chrono::duration<float, std::milli>(search_time).count()));
}

TEST (Dict, consistency_test)
{
    auto d = Dict(huge_path);
    d.load_file();
    d.calculate_word_freq();

    EXPECT_EQ((int)d.size(), 213637);

    std::ifstream input( example_path );
    auto map = d.get_map();
    for( std::string line; getline( input, line ); )
    {
        auto pos = line.find(' ');
        auto word = line.substr(pos+1, line.size());
        auto value = line.substr(0, pos);
        EXPECT_EQ(map[word], std::stoi(value));
    }
}
