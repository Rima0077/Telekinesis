#include "vector.h"
#include <iostream>

int main() {
    // Test default constructor
    g3::vector<int> vec1;
    std::cout << "Default constructed vector, size: " << vec1.size() << ", capacity: " << vec1.capacity() << std::endl;

    /* Test push_back and size
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    std::cout << "After push_back, vector contents: ";
    for (const auto& val : vec1) {
        std::cout << val << " ";
    }
    std::cout << "\nSize: " << vec1.size() << ", Capacity: " << vec1.capacity() << std::endl;

    // Test copy constructor
    g3::vector<int> vec2(vec1);
    std::cout << "Copy constructed vector, contents: ";
    for (const auto& val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Test move constructor
    g3::vector<int> vec3(std::move(vec2));
    std::cout << "Move constructed vector, contents: ";
    for (const auto& val : vec3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Test initializer list constructor
    g3::vector<int> vec4{4, 5, 6, 7};
    std::cout << "Initializer list constructed vector, contents: ";
    for (const auto& val : vec4) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Test resize
    vec4.resize(6, 8);
    std::cout << "After resize, vector contents: ";
    for (const auto& val : vec4) {
        std::cout << val << " ";
    }
    std::cout << "\nSize: " << vec4.size() << std::endl;

    // Test operator[]
    std::cout << "Element at index 2: " << vec4[2] << std::endl;

    // Test at() with out-of-range check
    try {
        std::cout << "Element at index 10: " << vec4.at(10) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test front() and back()
    std::cout << "Front element: " << vec4.front() << ", Back element: " << vec4.back() << std::endl;

    // Test insert
    auto it = vec4.insert(vec4.begin() + 1, 9);
    std::cout << "After insert, vector contents: ";
    for (const auto& val : vec4) {
        std::cout << val << " ";
    }
    std::cout << "\nInserted element: " << *it << std::endl;

    // Test erase
    it = vec4.erase(vec4.begin() + 2);
    std::cout << "After erase, vector contents: ";
    for (const auto& val : vec4) {
        std::cout << val << " ";
    }
    std::cout << "\nElement after erased element: " << *it << std::endl;

    // Test clear and empty
    vec4.clear();
    std::cout << "After clear, vector empty: " << std::boolalpha << vec4.empty() << std::endl;

    // Test relational operators
    g3::vector<int> vec5{1, 2, 3};
    g3::vector<int> vec6{1, 2, 3, 4};
    std::cout << "vec5 == vec6: " << (vec5 == vec6) << std::endl;
    std::cout << "vec5 != vec6: " << (vec5 != vec6) << std::endl;
    std::cout << "vec5 < vec6: " << (vec5 < vec6) << std::endl;
    std::cout << "vec5 <= vec6: " << (vec5 <= vec6) << std::endl;
    std::cout << "vec5 > vec6: " << (vec5 > vec6) << std::endl;
    std::cout << "vec5 >= vec6: " << (vec5 >= vec6) << std::endl;
*/
    return 0;
}

