#include <vector>
#include <iostream>
#include <algorithm>    // for find algorithm

using namespace std;

int main()
{
    cout << "Creating empty double vector" << endl << endl;
    vector<double> list;

    if (list.empty()) {
        cout << "front() would result in undefined behavior because vector is empty." << endl;
    } else {
        cout << "Using front() on vector: " << list.front() << endl;
    }

    if (list.empty()) {
        cout << "back() would result in undefined behavior because vector is empty." << endl << endl;
    } else {
        cout << "Using back() on vector: " << list.back() << endl << endl;
    }

    cout << "Using emplace() to add 2.0 to vector: " << endl << endl;
    list.emplace(list.begin(), 2.0);

    if (list.empty()) {
        cout << "front() would result in undefined behavior because vector is empty." << endl << endl;
    } else {
        cout << "Using front() on vector: " << list.front() << endl << endl;
    }

    cout << "Checking values in list: " << endl;

    // Check values 0, 1, 2, 3
    for(int i = 0; i < 4; i++){
        // If the vector contains i
        if(find(list.begin(), list.end(), double(i)) != list.end()){
            cout << "The value " << double(i) << " is in the list" << endl;
        } else {
            cout << "The value " << double(i) << " is NOT in the list" << endl;
        }
    }

    return 0;
}