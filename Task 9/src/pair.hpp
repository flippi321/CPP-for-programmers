#include <iostream>

using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(const T1& value1, const T2& value2) : first(value1), second(value2) {};

    auto getSum() const {
        return first + second;
        // return static_cast<double>(first) + static_cast<double>(second);
    }

    auto operator>(const Pair &other) const {
        return getSum() > other.getSum();
    }

    Pair operator+(const Pair &other) const {
        auto newFirst = first + other.first;
        auto newSecond = second + other.second;
        return Pair(newFirst, newSecond);
    }
};