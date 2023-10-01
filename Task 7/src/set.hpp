//
// set.hpp
//
#pragma once
#include <utility>
#include <vector>
#include <iostream>

class Set {
public:
    std::string name;
    std::vector<int> contents;

    Set();
    Set(int list[], int size, std::string name);
    void add(int value);
    std::vector<int> getUnion(const Set &other) const;
    Set &operator=(const Set &other);
    void getSet();
};

//-------------------------------------------------------------------
//                          Implementation
//-------------------------------------------------------------------

Set::Set() : contents(), name("Set") {}

// Initialize set contents using array
Set::Set(int list[], int size, std::string name) : contents(list, list + size), name(std::move(name))  {}

// Add element to the end of the list
void Set::add(int value) {
    contents.push_back(value);
}

std::vector<int> Set::getUnion(const Set &other) const {
    std::vector<int> unionSet = contents;

    for (int value : other.contents) {
        // Check if the element is not already in 'unionSet'
        bool found = false;
        for (int existing : unionSet) {
            if (existing == value) {
                found = true;
                break;
            }
        }
        if (!found) {
            unionSet.push_back(value);
        }
    }

    return unionSet;
}

Set &Set::operator=(const Set &other) {
    contents = other.contents;
    return *this;
}

// Add element to the end of the list
void Set::getSet() {
    std::cout << name << ": { ";
    for (int value : contents) {
        std::cout << value << " ";
    }
    std::cout << "}" << std::endl;
}