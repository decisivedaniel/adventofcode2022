#include <iostream>
#include <fstream>
#include <string>

int input()
{
    std::ifstream input("input.txt");
    int maximum = 0;
    int secondMax = 0;
    int thirdMax = 0;
    std::string current;
    int currentElfTotal = 0;
    int elf = 1;
    int maxElf = 0;
    while (getline(input, current))
    {
        if (current != "")
        {
           currentElfTotal += stoi(current);
        }
        else
        {
            if (currentElfTotal > maximum)
            {
                thirdMax = secondMax;
                secondMax = maximum;
                maximum = currentElfTotal;
            }
            else if (currentElfTotal > secondMax)
            {
                thirdMax = secondMax;
                secondMax = currentElfTotal;
            }
            else if (currentElfTotal > thirdMax)
            {
                thirdMax = currentElfTotal;
            }
            currentElfTotal = 0;
        }
    }
    input.close();
    std::cout << maximum << " " << secondMax << " " << thirdMax << std::endl;
    maximum = maximum + secondMax + thirdMax;
    return maximum;
}

int main()
{
    int maximum = input();
    std::cout << maximum << std::endl;
}