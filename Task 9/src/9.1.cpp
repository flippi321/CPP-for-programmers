#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

// Function used in 9b for checking if 2 values are "approximately equal"
bool isApproximatelyEqual(int a, int b) {
    return abs(a - b) <= 2;
}

void printEquality(bool isEqual, int number){
    if (isEqual) {
        cout << "Intervallet [v1.begin(), v1.begin() + " << number <<"> og v2 er omtrent like." << endl;
    } else {
        cout << "Intervallet [v1.begin(), v1.begin() + 5> og v2 er ikke omtrent like." << endl;
    }
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;
    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    // A:
    auto it = find_if(v1.begin(), v1.end(), [](int element) {
        return element > 15;
    });

    if (it != v1.end()) {
        cout << "Det første elementet i v1 som er større enn 15: " << *it << endl;
    } else {
        cout << "Ingen elementer i v1 er større enn 15." << endl;
    }

    // B:
    bool isApproximatelyEqualInterval1 = equal(v1.begin(), v1.begin() + 5, v2.begin(), isApproximatelyEqual);
    bool isApproximatelyEqualInterval2 = equal(v1.begin(), v1.begin() + 4, v2.begin(), isApproximatelyEqual);
    printEquality(isApproximatelyEqualInterval1, 5);
    printEquality(isApproximatelyEqualInterval2, 4);
}