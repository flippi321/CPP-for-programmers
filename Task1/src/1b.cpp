#include <iostream>
#include <fstream>

void read_temperatures(double* temperatures, int length, int* bTen, int* aTwenty);

int main()
{
    constexpr int length = 5;
    int bTen = 0;
    int aTwenty = 0;
    double temperatures[length];

    std::cout << "Program that takes user input of " << length << " days' temperatures." << std::endl;

    read_temperatures(temperatures, length, &bTen, &aTwenty);

    std::cout << std::endl << "Temperature range | Amount of days"  << std::endl << std::endl 
    << "\t < 10 \t  | \t" << bTen << std::endl << std::endl 
    << "\t  10-20   | \t" << length - bTen - aTwenty << std::endl << std::endl
    << "\t > 20 \t  | \t" << aTwenty << std::endl << std::endl;

    return 0;
}

void read_temperatures(double* temperatures, int length, int* bTen, int* aTwenty) {
    std::ifstream inFile("temperatures.txt");
    
    if (!inFile) {
        std::cerr << "Failed to open temperatures.txt for reading!" << std::endl;
        return;
    }
    
    for (int i = 0; i < length && inFile >> temperatures[i]; ++i) {
        if (temperatures[i] < 10.0) {
            bTen++;
        } else if (temperatures[i] > 20.0) {
            aTwenty++;
        }
    }

    inFile.close();
}