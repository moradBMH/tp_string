#include <iostream>
#include "string.h"
#include "string.cpp"


int main() {
    // Test Default Constructor
    string str1;
    std::cout << "str1 (default constructor): " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    // Test Constructor from a C-style string
    string str2("Hello, World!");
    std::cout << "str2 (from C-string): " << str2.c_str() << ", Size: " << str2.size() << std::endl;

    // Test Character Constructor
    string str3('A');
    std::cout << "str3 (character constructor): " << str3.c_str() << ", Size: " << str3.size() << std::endl;

    // Test Copy Constructor
    string str4(str2);
    std::cout << "str4 (copy constructor from str2): " << str4.c_str() << ", Size: " << str4.size() << std::endl;

    // Test Concatenation Operator
    string str5 = str2 + str3;  // Concatenate str2 and str3
    std::cout << "str5 (str2 + str3): " << str5.c_str() << ", Size: " << str5.size() << std::endl;

    // Test Assignment operator with a single character
    str1 = 'B';
    std::cout << "str1 after assignment with 'B': " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    // Test Assignment operator with another string
    str1 = str2;
    std::cout << "str1 after assignment with str2: " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    // Test the clear function
    str1.clear();
    std::cout << "str1 after clear: " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    // Test the destructor (automatically called when going out of scope)
    return 0;
}
