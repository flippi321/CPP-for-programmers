#include <iostream>
#include <limits>

int main()
{
    constexpr int length = 5;
    int bTen = 0;
    int aTwenty = 0;

    std::cout << "Program that takes user input of " << length << " days' temperatures." << std::endl;
    for(int counter = 1; counter <= length; counter++)
    {
        double currentInput;

        std::cout << "Please enter a double for the temperature on day " << counter << ":" << std::endl;

        if(std::cin >> currentInput)
        {
            std::cout << "Temperature nr " << counter << ": " << currentInput << std::endl;
            
            if(currentInput < 10)
            {
                bTen++;
            }
            else if(currentInput >= 20)
            {
                aTwenty++;
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Detected wrong input format, please try again" << std::endl << std::endl;
            continue;
        }
    }

    std::cout << std::endl << "Temperature range | Amount of days"  << std::endl << std::endl 
    << "\t < 10 \t  | \t" << bTen << std::endl << std::endl 
    << "\t  10-20   | \t" << length - bTen - aTwenty << std::endl << std::endl
    << "\t > 20 \t  | \t" << aTwenty << std::endl << std::endl;

    return 0;
}