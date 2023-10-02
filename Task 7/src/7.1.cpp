//
// fraction/main.cpp
//
#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c = a - 5;
  Fraction d = 5 - b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  return 0;
}