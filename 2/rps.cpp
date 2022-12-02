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
    X = 0, //need to lose
    Y = 3, //need to draw
    Z = 6 // need to
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
    winState outcome;
    int score = 0;
    while (input >> leftElfInput >> yoursElfInput)
    {
        leftElf = static_cast<leftElfOptions>(leftElfInput - 'A' + 1);
        outcome = static_cast<winState>((yoursElfInput - 'X') * 3);
        score += outcome;

        switch(outcome)
        {
            case Draw:
                score += leftElf;
                break;
            case Win:
                score += (leftElf % 3) + 1;
                break;
            case Lose:
                score += ((leftElf + 1) % 3) + 1;
                break;
        }

        std::cout << score << std::endl;
        
    }
    std::cout << score << std::endl;
}