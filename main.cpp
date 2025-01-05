#include <iostream>
#include "string.h"
#include "string.cpp"

int main() {
    // Default Constructor
    string str1;
    std::cout << "str1 (default constructor): " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    // Constructor from a C-style string
    string str2("Hello, World!");
    std::cout << "str2 (from C-string): " << str2.c_str() << ", Size: " << str2.size() << std::endl;

    // Character Constructor
    string str3('A');
    std::cout << "str3 (character constructor): " << str3.c_str() << ", Size: " << str3.size() << std::endl;

    // Copy Constructor
    string str4(str2);
    std::cout << "str4 (copy constructor from str2): " << str4.c_str() << ", Size: " << str4.size() << std::endl;


    // Clear Function
    str1.clear();
    std::cout << "str1 after clear: " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    // Resize Method
    str2.resize(5, 'X');
    std::cout << "str2 after resize(5, 'X'): " << str2.c_str() << ", Size: " << str2.size() << std::endl;
    str2.resize(10, 'Y');
    std::cout << "str2 after resize(10, 'Y'): " << str2.c_str() << ", Size: " << str2.size() << std::endl;

    // Max Size
    std::cout << "Max size: " << str2.max_size() << std::endl;

    // Length
    std::cout << "str2 length: " << str2.length() << std::endl;

    // c_str Method
    const char* c_string = str2.c_str();
    std::cout << "Testing c_str() for str2: " << c_string << std::endl;


    // Concatenation Operator with a character (string + char)
    string str5 = str2 + 'A';
    std::cout << "str5 (str2 + 'A'): " << str5.c_str() << ", Size: " << str5.size() << std::endl;

    // Concatenation Operator with a C-string (string + const char*)
    string str6 = str2 + ", how are you?";
    std::cout << "str6 (str2 + \", how are you?\"): " << str6.c_str() << ", Size: " << str6.size() << std::endl;

    // Concatenation Operator with another string
    string str7(" Another string.");
    string str8 = str2 + str7;  // Concatenate str2 and str7
    std::cout << "str8 (str2 + str7): " << str8.c_str() << ", Size: " << str8.size() << std::endl;


    // Assignment Operator with a Single Character
    str1 = 'B';
    std::cout << "str1 after assignment with 'B': " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    // Assignment Operator with Another String
    str1 = str2;
    std::cout << "str1 after assignment with str2: " << str1.c_str() << ", Size: " << str1.size() << std::endl;

    return 0;
}
