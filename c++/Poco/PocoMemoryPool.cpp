#include "Poco/MemoryPool.h" 
#include <string> 
#include <iostream> 
using Poco::MemoryPool; 

int main(int argc, char** argv) 
{ 
    MemoryPool pool(1024); // unlimited number of 1024 byte blocks 
    char* buffer = reinterpret_cast<char*>(pool.get()); 
    std::cin.read(buffer, pool.blockSize()); 
    std::streamsize n = std::cin.gcount(); 
    std::string s(buffer, n); 
    pool.release(buffer); 
    std::cout << s << std::endl; 
    return 0; 
} 