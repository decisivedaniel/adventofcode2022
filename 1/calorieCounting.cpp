#include <iostream>

int input()
{
    int maximum = 0;
    int current = 0;
    int currentElfTotal = 0;
    while (current >= 0)
    {
        std::cin >> current;
        if (current > 0)
        {
           currentElfTotal += current;
        }
        if (current == 0)
        {
            if (currentElfTotal > maximum)
            {
                maximum == currentElfTotal;
                currentElfTotal = 0;
            }
        }
    }

    return maximum;
}

int main()
{
    int maximum = input();
    std::cout << maximum << std::endl;
}