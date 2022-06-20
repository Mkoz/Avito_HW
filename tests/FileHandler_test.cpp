#include "gtest/gtest.h"
#include "../service/FileHandler.h"

// do not really want to make magic with relative paths and glob
#define huge_path "D:\\CLionProjects\\Avito_HW\\files\\huge.txt"
#define example_path "D:\\CLionProjects\\Avito_HW\\files\\out_huge.txt"

TEST (FileHandler, load_file_huge)
{
    auto test_f = FileHandler(huge_path);
    test_f.init();
    EXPECT_EQ(test_f.size(), 336183276);
}

TEST (FileHandler, load_file_example)
{
    auto test_f_e = FileHandler(example_path);
    test_f_e.init();
    EXPECT_EQ(test_f_e.size(), 2395213);
}

TEST (FileHandler, check_line_numbers)
{
    auto test_f = FileHandler(huge_path);
    test_f.init();
    auto line_count = 0;
    for(auto i = 0; i < test_f.size(); ++i)
    {
        if ( *(test_f.get_full_content() + i) == '\n')
            line_count++;
    }
    EXPECT_EQ(line_count, 6455997);

    auto test_f_e = FileHandler(example_path);
    test_f_e.init();
    line_count = 0;
    for(auto i = 0; i < test_f_e.size(); ++i)
    {
        if ( *(test_f_e.get_full_content() + i) == '\n')
            line_count++;
    }
    EXPECT_EQ(line_count, 213637);
}
