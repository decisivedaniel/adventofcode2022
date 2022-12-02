#include <iostream>
#include <fstream>

enum leftElfOptions
{
    A = 1,
    B = 2,
    C = 3
};

enum yoursElfOptions
{
    X = 1,
    Y = 2,
    Z = 3
};

enum winState
{
    Lose = 0,
    Draw = 3,
    Win = 6
};

int main()
{
    std::ifstream input("input.txt");
    char leftElfInput;
    char yoursElfInput;
    leftElfOptions leftElf;
    yoursElfOptions yoursElf;
    int score = 0;
    while (input >> leftElfInput >> yoursElfInput)
    {
        leftElf = static_cast<leftElfOptions>(leftElfInput - 'A' + 1);
        yoursElf = static_cast<yoursElfOptions>(yoursElfInput - 'X' + 1);
        score += yoursElf;
        switch(leftElf - yoursElf)
        {
            case 0:
                score += Draw;
                break;
            case 1:
            case -2:
                score += Lose;
                break;
            case -1:
            case 2:
                score += Win;
                break;
            default:
                std::cout << "messed up" << std::endl;
        }
        
    }
    std::cout << score << std::endl;
}