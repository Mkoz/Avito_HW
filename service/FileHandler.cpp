#include "FileHandler.h"

FileHandler::FileHandler(const char* aFile)
{
    _file_name = aFile;
    _file_desc = open(aFile, O_RDONLY);
    _mem_magic_ptr = nullptr;
}

FileHandler::~FileHandler()
{
    close(_file_desc);
    // free mmap
    munmap((void *) _mem_magic_ptr, size());
}

void FileHandler::init()
{
    if (_file_desc == -1)
    {
        // TODO define own exception type
        throw std::runtime_error("Cannot open file: " + _file_name);
    }

    // Get file info
    if (fstat(_file_desc, &_stats) == -1)
    {
        throw std::runtime_error("Cannot get stats for file: " + _file_name);
    }

    // Mapping file to the memory
    _mem_magic_ptr = static_cast<const char*>(mmap(NULL, this->size(), PROT_READ, MAP_PRIVATE, _file_desc, 0u));
    if (_mem_magic_ptr == MAP_FAILED) {
        throw std::runtime_error("Cannot map file: " + _file_name + " to memory");
    }
    _current_size = _stats.st_size;
}








