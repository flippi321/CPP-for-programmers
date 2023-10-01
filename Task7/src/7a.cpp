//
// fraction/main.cpp
//
#include "fraction.hpp"
#include "fractionOperations.hpp"
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
  //Fraction d = b - 5;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  //print("d = ", d);
}