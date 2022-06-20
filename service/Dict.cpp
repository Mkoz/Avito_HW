//
// Created by Хозяин on 20.06.2022.
//

#include "Dict.h"

Dict::Dict(const char * aFile): _f(aFile) // pre construction init is mandatory for objects without default constructor
{
    //_f = std::move(FileHandler(aFile));
    //pprint << "Constructor" << std::endl;
}

Dict::~Dict()
{
    delete _o_map;
}

void Dict::load_file()
{
    try
    {
        _f.init();
        //pprint << "Init" << std::endl;
    }
    catch (std::runtime_error anError)
    {
        pprint << anError.what() << std::endl;
    }
}

void Dict::calculate_word_freq()
{
    // Don't we really want store such a big object at the stack, lets use heap
    auto theMap = std::make_unique<std::unordered_map<std::string , int>>();
    std::string tmp;
    auto ptr = _f.get_full_content();
    // size calculation will be handled by named return value optimization
    for(auto i = 0; i < _f.size(); ++i)
    {
        // TODO make magic literals more magic static members like Dict::rules.start_liter
        // TODO make conversion from char to int for magic values constexpr
        if('A' <= *(ptr + i) && *(ptr + i) <= 'Z')
        {
            tmp += *(ptr + i) + 32; // 32 is distance between capitals and small letters 'A' + 32 is 'a'
        }
        else if ('a' <= *(ptr + i) && *(ptr + i) <= 'z')
        {
            tmp += *(ptr + i);
        }
        else
        {
            if(!tmp.empty())
            {
                // Lets do note make useless copy
                ++(*theMap)[std::move(tmp)];
                tmp.clear();
            }
        }
    }
    _o_map = new std::map<std::string, int> (theMap->begin(), theMap->end());

}