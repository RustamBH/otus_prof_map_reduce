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
    //std::vector<int> map_output;
    while (std::getline(std::cin, line))
    {
        std::stringstream string_stream(line);
        int i = 0;
        while (std::getline(string_stream, item, delimiter)) {
            if (column == i) {
                //map_output.push_back(stoi(item));
                std::cout << item << "\t" << "1" << std::endl;
                break;
            }
            i++;
        }
    }

    return 0;
}