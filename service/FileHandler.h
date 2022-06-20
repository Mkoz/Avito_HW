#pragma once

#include <exception>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <unistd.h>

// for mmap:
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

class FileHandler {

public:
    //TODO make constructor without args and some set/init methods
    FileHandler() = delete;

    explicit FileHandler(const char*);
    ~FileHandler();

    void init();
    inline const off_t& size() { return _stats.st_size;};
    // TODO implement more complex line navigation
    const char* get_next_line();
    inline const char* get_full_content() { return _mem_magic_ptr;};


private:
    int _file_desc;
    struct stat _stats;

    // NOTE _file_name might be removed and some stack space can be saved, added just for making exception more informative
    std::string _file_name;
    const char* _mem_magic_ptr = nullptr;
    // TODO think about another line separators?
    char _line_sep = '\n';
};

