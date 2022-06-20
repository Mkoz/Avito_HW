#include <iostream>
#include <map>
#include <ctime>
#include <chrono>
#include <string.h>
#include "service/Dict.h"

// do not really want to make magic with relative paths and glob
#define input_f "D:\\CLionProjects\\Avito_HW\\files\\huge.txt"

//pprint from Dict.h

int main() {
    auto start_time =  std::chrono::high_resolution_clock::now();

    auto d = Dict(input_f);
    d.load_file();
    d.calculate_word_freq();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto search_time = end_time - start_time;

    pprint << "d.size() is " << d.size() << std::endl;
    pprint << "Oh, So long: " << std::chrono::duration<double, std::milli>(search_time).count() << " milliseconds"<< std::endl;
}
