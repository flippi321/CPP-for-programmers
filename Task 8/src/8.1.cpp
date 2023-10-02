//
// fraction/main.cpp
//
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename Type> bool equal(Type a, Type b) {
    if (a == b){
        return true;
    }
    return false;
}

// Specialized method for double values
bool equal(double a, double b) {
    const double toleranse = 0.00001;
    if (fabs(a - b) < toleranse) {
        return true;
    }
    return false;
}

template <typename Type> void printEqual(Type a, Type b) {
    if (equal(a, b)){
        cout << a << " equals " << setprecision(10) << b << endl;
    } else {
        cout << a << " does not equal " << b << endl;
    }
}

int main() {
  double a = 1.0;
  double b = 1.0;

  int c = 1;
  int d = 2;

  printEqual(a, b);
  printEqual(c, d);

  return 0;
}