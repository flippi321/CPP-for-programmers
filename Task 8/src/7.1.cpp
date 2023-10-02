//
// fraction/main.cpp
//
#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

template <typename Type> bool equal(Type a, Type b) {
  if (a == b){
    return true;
  } else {
    return a.equals(b)
  }
}

int main() {
  double a = 1.0;
  double b = 2.0;

  cout << equal(a, b) << endl;
  return 0;
}