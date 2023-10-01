#include "set.hpp"
#include <iostream>

int main() {
    // Create two sets
    int arr1[] = {1, 2};
    Set set1(arr1, 2, "Set1");
    set1.getSet();

    int arr2[] = {2,  4, 5};
    Set set2(arr2, 3, "Set2");
    set2.getSet();
    std::cout << std::endl;

    // Test add method
    set1.add(3);
    std::cout << "Adding 3 to Set1" << std::endl;
    set1.getSet();
    std::cout << std::endl;

    // Test add method
    set2.add(3);
    std::cout << "Adding 3 to Set2" << std::endl;
    set2.getSet();
    std::cout << std::endl;

    // Test getUnion method
    std::vector<int> unionResult = set1.getUnion(set2);

    // Show union
    std::cout << "Union of Set 1 and Set 2: { ";
    for (int value : unionResult) {
        std::cout << value << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "Create empty set:" << std::endl;
    Set set3 = Set();
    set3.getSet();
    std::cout << std::endl << "Use set3 = set1:" << std::endl;
    set3 = set1;
    set3.getSet();

    return 0;
}
