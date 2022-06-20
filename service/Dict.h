#pragma once

#include "FileHandler.h"

#include <memory>

// Already included at FileHandler, but lets save it for visual code consistency
#include <string>
#include <map>
#include <unistd.h>
#define pprint std::cout<< __FILE__ << ":" << __LINE__ << " ::" << __PRETTY_FUNCTION__ << " "


class Dict {
public:
    // TODO create default constructor and procedure for post fact initialization
    Dict() = delete;
    ~Dict();
    explicit Dict(const char *);

    // TODO create print_to_file()
    void print();
    inline const char* get() { return _f.get_full_content();};
    inline const std::map<std::string, int>& get_map() { return *_o_map;};
    inline const size_t size() {return _o_map->size();};
    void load_file();
    void calculate_word_freq();

private:
    FileHandler _f;
    // Usual pointer 0.3 sec faster std::unique_ptr
    std::map<std::string, int>* _o_map;

};

