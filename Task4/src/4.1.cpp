#include <vector>
#include <iostream>
#include <algorithm>    // for find algorithm

using namespace std;

int main()
{
    cout << "Creating empty vector" << endl;
    vector<double> list;

    cout << "Using front() on vector: " << list.front() << endl;
    cout << "Using back() on vector: " << list.back() << endl;

    cout << "Using emplace() to add 2.0 to vector: " << endl;
    list.emplace(list.begin(), 2.0);
    cout << "Using front() on vector: " << list.front() << endl;

    // Check values 0, 1, 2
    for(int i = 0; i < 3; i++){
        // If the vector contains i
        if(find(list.begin(), list.end(), double(i)) != list.end()){
            cout << "The value " << double(i) << " is in the list" << endl;
        } else {
            cout << "The value " << double(i) << " is NOT in the list" << endl;
        }
    }

    return 0;
}