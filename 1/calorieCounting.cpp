#include <iostream>
#include <fstream>
#include <string>

int input()
{
    std::ifstream input("input.txt");
    int maximum = 0;
    std::string current;
    int currentElfTotal = 0;
    int elf = 1;
    int maxElf = 0;
    while (getline(input, current))
    {
        //std::cout << current << std::endl;
        if (current != "")
        {
           currentElfTotal += stoi(current);
        }
        else
        {
            if (currentElfTotal > maximum)
            {
                maximum = currentElfTotal;
                maxElf = elf;
                std::cout << maximum << std::endl;
            }
            currentElfTotal = 0;
            elf++;
        }
    }
    input.close();
    std::cout << maxElf << "has ";
    return maximum;
}

int main()
{
    int maximum = input();
    std::cout << maximum << std::endl;
}