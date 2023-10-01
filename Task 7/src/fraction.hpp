//
// fraction.hpp
//
#pragma once

class Fraction {
public:
  int numerator;
  int denominator;

  Fraction();
  Fraction(int numerator, int denominator);
  void set(int numerator_, int denominator_ = 1);
  Fraction operator+(const Fraction &other) const;
  Fraction operator-(const Fraction &other) const;
  Fraction operator-(const int &other) const;
  friend Fraction operator-(int integer, const Fraction &other);
  Fraction operator*(const Fraction &other) const;
  Fraction operator/(const Fraction &other) const;
  Fraction operator-() const;
  Fraction &operator++(); // Preinkrement
  Fraction &operator--(); // Predekrement
  Fraction &operator+=(const Fraction &other);
  Fraction &operator-=(const Fraction &other);
  Fraction &operator*=(const Fraction &other);
  Fraction &operator/=(const Fraction &other);
  Fraction &operator=(const Fraction &other);
  bool operator==(const Fraction &other) const;
  bool operator!=(const Fraction &other) const;
  bool operator<=(const Fraction &other) const;
  bool operator>=(const Fraction &other) const;
  bool operator<(const Fraction &other) const;
  bool operator>(const Fraction &other) const;

private:
  void reduce();
  int compare(const Fraction &other) const;
};

//-------------------------------------------------------------------
//
// Implementation
// 
//-------------------------------------------------------------------
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numberator, int denominator) {
    set(numberator, denominator);
}

void Fraction::set(int numberator_, int denominator_) {
    if (denominator_ != 0) {
        numerator = numberator_;
        denominator = denominator_;
        reduce();
    } else {
        throw "nevneren ble null";
    }
}

Fraction Fraction::operator+(const Fraction &other) const {
    Fraction fraction = *this;
    fraction += other;
    return fraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
    set(numerator * other.denominator + denominator * other.numerator,
        denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator-(const Fraction &other) const {
    Fraction fraction = *this;
    fraction -= other;
    return fraction;
}

Fraction Fraction::operator-(const int &other) const {
    Fraction fraction = *this;
    /* Alternative method
     * for(int i = 0; i < other; i++){
     *    --fraction;
     * }
     */

    // Method 2
    fraction.numerator -= fraction.denominator * other;
    return fraction;
}

Fraction operator-(int integer, const Fraction &other) {
    // We find the opposite and multiply this by -1
    Fraction fraction = other - integer;
    return -fraction;
}

Fraction &Fraction::operator-=(const Fraction &other) {
    set(numerator * other.denominator - denominator * other.numerator,
        denominator * other.denominator);
    return *this;
}

Fraction &Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator-() const {
    Fraction fraction;
    fraction.numerator = -numerator;
    fraction.denominator = denominator;
    return fraction;
}

Fraction Fraction::operator*(const Fraction &other) const {
    Fraction fraction = *this;
    fraction *= other;
    return fraction;
}

Fraction &Fraction::operator*=(const Fraction &other) {
    set(numerator * other.numerator, denominator * other.denominator);
    return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
    Fraction fraction = *this;
    fraction /= other;
    return fraction;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    set(numerator * other.denominator, denominator * other.numerator);
    return *this;
}

Fraction &Fraction::operator=(const Fraction &other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

bool Fraction::operator==(const Fraction &other) const {
    return (compare(other) == 0) ? true : false;
}

bool Fraction::operator!=(const Fraction &other) const {
    return (compare(other) != 0) ? true : false;
}

bool Fraction::operator<=(const Fraction &other) const {
    return (compare(other) <= 0) ? true : false;
}

bool Fraction::operator>=(const Fraction &other) const {
    return (compare(other) >= 0) ? true : false;
}

bool Fraction::operator<(const Fraction &other) const {
    return (compare(other) < 0) ? true : false;
}

bool Fraction::operator>(const Fraction &other) const {
    return (compare(other) > 0) ? true : false;
}

//-------------------------------------------------------------------
//
// Sørg for at nevneren alltid er positiv.
// Bruker Euclids algoritme for å finne fellesnevneren.
//
void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int a = numerator;
    int b = denominator;
    int c;
    if (a < 0)
        a = -a;

    while (b > 0) {
        c = a % b;
        a = b;
        b = c;
    }
    numerator /= a;
    denominator /= a;
}

//-------------------------------------------------------------------
//
// Returnerer +1 hvis *this > other, 0 hvis de er like, -1 ellers
//
int Fraction::compare(const Fraction &other) const {
    Fraction fraction = *this - other;
    if (fraction.numerator > 0)
        return 1;
    else if (fraction.numerator == 0)
        return 0;
    else
        return -1;
}