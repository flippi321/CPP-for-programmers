//
// fraction/main.cpp
//
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Task specified the '==' operator would be defined by the values
template <typename Type> bool equal(Type a, Type b) {
    return (a==b);
}

// Specialized method for double values
bool equal(double a, double b) {
    const double toleranse = 0.00001;
    if (fabs(a - b) < toleranse) {
        return true;
    }
    return false;
}

// Template method using any of the two templates and prints out the response
template <typename Type> void printEqual(Type a, Type b) {
    if (equal(a, b)){
        cout << a << " equals " << setprecision(10) << b << endl;
    } else {
        cout << a << " does not equal " << b << endl;
    }
}

int main() {
  double a = 1.5;
  double b1 = 1.50001;
  double b2 = 1.500001;

  int c = 1;
  int d1 = 1;
  int d2 = 2;

  printEqual(a, b1);
  printEqual(a, b2);
  printEqual(c, d1);
  printEqual(c, d2);

  return 0;
}