#include <iostream>
#include "circle.hpp"

int main() {
  Circle circle = Circle(5);                          // Initiated object

  int area = circle.get_area();                       // Added "int"
  cout << "Arealet er lik " << area << endl;          // Prints area too

  double circumference = circle.get_circumference();   
  cout << "Omkretsen er lik " << circumference << endl;
}