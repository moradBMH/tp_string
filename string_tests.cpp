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


    // Test Concatenation Operator with a string and a character
    string str5 = str2 + '!';
    std::cout << "str5 (str2 + '!'): " << str5.c_str() << ", Size: " << str5.size() << std::endl;

    // Test Concatenation Operator with a string and a C-string
    string str6 = str2 + ", how are you?";
    std::cout << "str6 (str2 + \", how are you?\"): " << str6.c_str() << ", Size: " << str6.size() << std::endl;

    // Test concatenation operator+(const string&, const string&)
    string str9 = str3 + str4;
    std::cout << "str9 (str3 + str4): " << str9.c_str() << ", Size: " << str9.size() << std::endl;


    // Test Assignment operator with a single character
    str1 = 'B';
    std::cout << "str1 after assignment with 'B': " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    // Test Assignment operator with another string
    str1 = str2;
    std::cout << "str1 after assignment with str2: " << str1.c_str() << ", Size: " << str1.size() << std::endl;


    // Test clear function
    str1.clear();
    std::cout << "str1 after clear: " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    // Test c_str method (ensuring it returns a proper C-string)
    const char* c_string = str2.c_str();
    std::cout << "Testing c_str() for str2: " << c_string << std::endl;

    // Test length() method
    std::cout << "str2 length: " << str2.length() << std::endl;

    // Test max_size() method
    std::cout << "str2 max_size: " << str2.max_size() << std::endl;

    // Test resize() method
    str2.resize(5, 'X');
    std::cout << "str2 after resize(5, 'X'): " << str2.c_str() << ", Size: " << str2.size() << std::endl;

    str2.resize(10, 'Y');
    std::cout << "str2 after resize(10, 'Y'): " << str2.c_str() << ", Size: " << str2.size() << std::endl;

    return 0;
}
