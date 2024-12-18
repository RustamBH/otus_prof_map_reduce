#include <iostream>
#include <string>
#include <vector>
#include <sstream>


int main(int argc, char ** argv)
{
    std::string line;	
    std::string item;
    char delimiter = ',';
    std::stringstream string_stream;
    std::size_t column = 9; // price

    // Map    
    while (std::getline(std::cin, line))
    {
        std::stringstream string_stream(line);
        int i = 0;
        while (std::getline(string_stream, item, delimiter)) {
            if (column == i) {                
                std::cout << item << "\t" << "1" << std::endl;
                break;
            }
            i++;
        }
    }

    return 0;
}
