const double pi = 3.141592;

class Circle {
  public:
    Circle(double radius_);                 // Didn't use a capital letter
    int get_area() const;
    double get_circumference() const;
  private: 
    double radius;                          // Didn't have ":" after private
};                                          // Added semicolon

// ==> Implementasjon av klassen Circle
Circle::Circle(double radius_) : radius(radius_) {}   // Don't need public here, flipped "radius" and "radius_"

int Circle::get_area() const {                        // Added Const
  return pi * radius * radius;
}

double Circle::get_circumference() const {            // Added double    
  return 2.0 * pi * radius;                           // Returned the circumfernece directly (It wasn't declared with ouble)
}