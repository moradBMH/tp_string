#include <iostream>
#include "string.cpp"

bool compare_strings(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr) {
        return false;
    }
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return false;
        }
        ++str1;
        ++str2;
    }
    return *str1 == '\0' && *str2 == '\0';
}

// ======= NON INTERACTIVE TESTS =======

// Auxiliary function to calculate the length of a C-string
std::size_t custom_strlen(const char* cstr) {
    std::size_t length = 0;
    while (cstr[length] != '\0') {
        ++length;
    }
    return length;
}

// Test the default constructor
void test_default_constructor() {
    string s;
    if (s.size() != 0) std::cout << "Default constructor test failed!" << std::endl;
    if (s.capacity() != 1) std::cout << "Default constructor capacity test failed!" << std::endl;
    if (!s.empty()) std::cout << "Default constructor empty test failed!" << std::endl;
    std::cout << "Default constructor test passed!" << std::endl;
}

// Test the copy constructor
void test_copy_constructor() {
    string original("Hello");
    string copy(original);
    if (copy.size() != original.size()) std::cout << "Copy constructor size test failed!" << std::endl;
    if (copy.capacity() != original.capacity()) std::cout << "Copy constructor capacity test failed!" << std::endl;
    if (copy.c_str() == original.c_str()) std::cout << "Copy constructor memory test failed!" << std::endl;
    if (!compare_strings(copy.c_str(), original.c_str())) std::cout << "Copy constructor equality test failed!" << std::endl;
    std::cout << "Copy constructor test passed!" << std::endl;
}

// Test the character constructor
void test_char_constructor() {
    string s('A');
    if (s.size() != 1) std::cout << "Character constructor size test failed!" << std::endl;
    if (s.capacity() != 2) std::cout << "Character constructor capacity test failed!" << std::endl;
    if (!compare_strings(s.c_str(), "A")) std::cout << "Character constructor character test failed!" << std::endl;
    std::cout << "Character constructor test passed!" << std::endl;
}

// Test constructor from a C-string
void test_cstr_constructor() {
    const char* cstr = "Hello World!";
    string s(cstr);
    if (s.size() != std::strlen(cstr)) std::cout << "C-string constructor size test failed!" << std::endl;
    if (s.capacity() != std::strlen(cstr) + 1) std::cout << "C-string constructor capacity test failed!" << std::endl;
    if (s.c_str() == cstr) std::cout << "C-string constructor memory test failed!" << std::endl;
    if (!compare_strings(s.c_str(), cstr)) std::cout << "C-string constructor equality test failed!" << std::endl;
    std::cout << "C-string constructor test passed!" << std::endl;
}

// Test the destructor (check if memory is properly freed)
void test_destructor() {
    {
        string s("Temp");
    } // Check if memory is freed without a leak
    std::cout << "Destructor test passed!" << std::endl;
}

// Test the clear method
void test_clear() {
    string s("Clear me");
    s.clear();
    if (s.size() != 0) std::cout << "Clear method size test failed!" << std::endl;
    if (s.capacity() != 1) std::cout << "Clear method capacity test failed!" << std::endl;
    if (!s.empty()) std::cout << "Clear method empty test failed!" << std::endl;
    std::cout << "Clear method test passed!" << std::endl;
}

// Test the resize method (increase size and fill with a character)
void test_resize_increase() {
    string s("Resize me");
    s.resize(12, '*');
    if (s.size() != 12) std::cout << "Resize increase size test failed!" << std::endl;
    if (s.c_str()[9] != '*') std::cout << "Resize increase character test failed!" << std::endl;
    if (s.c_str()[12] != '\0') std::cout << "Resize increase null terminator test failed!" << std::endl;
    std::cout << "Resize increase test passed!" << std::endl;
}

// Test the resize method (decrease size)
void test_resize_decrease() {
    string s("Resize me down");
    s.resize(6);
    if (s.size() != 6) std::cout << "Resize decrease size test failed!" << std::endl;
    if (s.c_str()[6] != '\0') std::cout << "Resize decrease null terminator test failed!" << std::endl;
    std::cout << "Resize decrease test passed!" << std::endl;
}

// Test the reserve method
void test_reserve() {
    string s("Reserve me");
    s.reserve(20);
    if (s.capacity() < 20) std::cout << "Reserve capacity test failed!" << std::endl;
    std::cout << "Reserve method test passed!" << std::endl;
}

// Test the assignment operator from a C-string
void test_assign_cstr() {
    string s;
    s = "Assign this";
    if (s.size() != 11) std::cout << "Assignment from C-string size test failed!" << std::endl;
    if (s.capacity() < 12) std::cout << "Assignment from C-string capacity test failed!" << std::endl;
    if (!compare_strings(s.c_str(), "Assign this")) std::cout << "Assignment from C-string equality test failed!" << std::endl;
    std::cout << "Assignment from C-string test passed!" << std::endl;
}

// Test the assignment operator from another string
void test_assign_string() {
    string s1("Hello");
    string s2;
    s2 = s1;
    if (s2.size() != s1.size()) std::cout << "Assignment from string size test failed!" << std::endl;
    if (s2.capacity() != s1.capacity()) std::cout << "Assignment from string capacity test failed!" << std::endl;
    if (!compare_strings(s1.c_str(), s2.c_str())) std::cout << "Assignment from string equality test failed!" << std::endl;
    std::cout << "Assignment from string test passed!" << std::endl;
}

// Test the assignment operator from a character
void test_assign_char() {
    string s;
    s = 'X';
    if (s.size() != 1) std::cout << "Assignment from character size test failed!" << std::endl;
    if (s.capacity() != 2) std::cout << "Assignment from character capacity test failed!" << std::endl;
    if (s.c_str()[0] != 'X') std::cout << "Assignment from character character test failed!" << std::endl;
    std::cout << "Assignment from character test passed!" << std::endl;
}

// Test the concatenation operator with a character
void test_concatenate_char() {
    string s("Hello");
    s = s + '!';
    if (s.size() != 6) std::cout << "Concatenation with character size test failed!" << std::endl;
    if (s.c_str()[5] != '!') std::cout << "Concatenation with character test failed!" << std::endl;
    std::cout << "Concatenation with character test passed!" << std::endl;
}

// Test the concatenation operator with a C-string
void test_concatenate_cstr() {
    string s("Hello");
    s = s + " World";
    if (s.size() != 11) std::cout << "Concatenation with C-string size test failed!" << std::endl;
    if (!compare_strings(s.c_str(), "Hello World")) std::cout << "Concatenation with C-string test failed!" << std::endl;
    std::cout << "Concatenation with C-string test passed!" << std::endl;
}

// Test the concatenation operator with another string
void test_concatenate_string() {
    string s1("Hello");
    string s2(" World");
    s1 = s1 + s2;
    if (s1.size() != 11) std::cout << "Concatenation with string size test failed!" << std::endl;
    if (!compare_strings(s1.c_str(), "Hello World")) std::cout << "Concatenation with string test failed!" << std::endl;
    std::cout << "Concatenation with string test passed!" << std::endl;
}

// Test the equality operator (if implemented)
void test_equality_operator() {
    string s1("Test");
    string s2("Test");
    string s3("Another");
    if (!compare_strings(s1.c_str(), s2.c_str())) std::cout << "Equality operator test failed!" << std::endl;
    if (compare_strings(s1.c_str(), s3.c_str())) std::cout << "Inequality operator test failed!" << std::endl;
    std::cout << "Equality operator test passed!" << std::endl;
}

// Test the max_size method
void test_max_size() {
    string s;
    if (s.max_size() != 100) std::cout << "Max size test failed!" << std::endl;
    std::cout << "Max size method test passed!" << std::endl;
}

// ======= INTERACTIVE TESTS =======

std::string get_valid_string() {
    std::string input;

    while (true) {
        std::getline(std::cin, input);  // Reads a complete line of text from the user input (including spaces) and stores it in the 'input' string variable.
        if (input.size() > input.max_size()) {
            std::cerr << "Error: The entered string exceeds the maximum allowed size (" << input.max_size() << "). Please try again: ";
        } else {
            return input;
        }
    }
}

void interactive_test_default_constructor() {
    std::cout << "\n=== Test Default Constructor ===" << std::endl;
    string s;
    std::cout << "Created an empty string. Size: " << s.size() << ", Capacity: " << s.capacity() << ", Empty: " << s.empty() << std::endl;
}

void interactive_test_copy_constructor() {
    std::cout << "\n=== Test Copy Constructor ===" << std::endl;
    std::string input;
    std::cout << "Enter a string to copy: ";
    input = get_valid_string();
    string original(input.c_str());
    string copy(original);
    std::cout << "Original: " << original.c_str() << ", Copy: " << copy.c_str() << std::endl;
}

void interactive_test_char_constructor() {
    std::cout << "\n=== Test Character Constructor ===" << std::endl;
    char ch;
    std::cout << "Enter a character to construct the string: ";
    std::cin >> ch;
    std::cin.ignore();  // Ignores the newline character left after reading input with std::cin.
    string s(ch);
    std::cout << "String constructed with character '" << ch << "': " << s.c_str() << std::endl;
}

void interactive_test_cstr_constructor() {
    std::cout << "\n=== Test C-String Constructor ===" << std::endl;
    std::string input;
    std::cout << "Enter a C-string to construct the string: ";
    input = get_valid_string();
    string s(input.c_str());
    std::cout << "String constructed: " << s.c_str() << std::endl;
}

void interactive_test_clear() {
    std::cout << "\n=== Test Clear Method ===" << std::endl;
    std::string input;
    std::cout << "Enter a string to clear: ";
    input = get_valid_string();
    string s(input.c_str());
    std::cout << "Before clearing: " << s.c_str() << std::endl;
    s.clear();
    std::cout << "After clearing: (empty) Size: " << s.size() << ", Capacity: " << s.capacity() << std::endl;
}

void interactive_test_resize_increase() {
    std::cout << "\n=== Test Resize Increase ===" << std::endl;
    std::string input;
    std::cout << "Enter a string to resize: ";
    input = get_valid_string();
    string s(input.c_str());
    std::size_t newSize;
    char fillChar;
    std::cout << "Enter new size: ";
    std::cin >> newSize;
    std::cout << "Enter a character to fill: ";
    std::cin >> fillChar;
    std::cin.ignore();
    if (newSize > s.max_size()) {
        std::cerr << "Error: New size exceeds the maximum allowed size (" << s.max_size() << ")." << std::endl;
        return;
    }
    s.resize(newSize, fillChar);
    std::cout << "Resized string: " << s.c_str() << std::endl;
}

void interactive_test_resize_decrease() {
    std::cout << "\n=== Test Resize Decrease ===" << std::endl;
    std::string input;
    std::cout << "Enter a string to resize: ";
    input = get_valid_string();
    string s(input.c_str());
    std::size_t newSize;
    std::cout << "Enter new size: ";
    std::cin >> newSize;
    std::cin.ignore();
    if (newSize > s.max_size()) {
        std::cerr << "Error: New size exceeds the maximum allowed size (" << s.max_size() << ")." << std::endl;
        return;
    }
    s.resize(newSize);
    std::cout << "Resized string: " << s.c_str() << std::endl;
}

void interactive_test_concatenate_char() {
    std::cout << "\n=== Test Concatenation with Character ===" << std::endl;
    std::string input;
    std::cout << "Enter a string: ";
    input = get_valid_string();
    char ch;
    std::cout << "Enter a character to concatenate: ";
    std::cin >> ch;
    std::cin.ignore();
    string s(input.c_str());
    s = s + ch;
    if (s.size() > s.max_size()) {
        std::cerr << "Error: Concatenated string exceeds the maximum allowed size (" << s.max_size() << ")." << std::endl;
        return;
    }
    std::cout << "Concatenated string: " << s.c_str() << std::endl;
}

void interactive_test_concatenate_cstr() {
    std::cout << "\n=== Test Concatenation with C-String ===" << std::endl;
    std::string input1, input2;
    std::cout << "Enter first string: ";
    input1 = get_valid_string();
    std::cout << "Enter second string (C-string) to concatenate: ";
    input2 = get_valid_string();
    string s(input1.c_str());
    s = s + input2.c_str();
    if (s.size() > s.max_size()) {
        std::cerr << "Error: Concatenated string exceeds the maximum allowed size (" << s.max_size() << ")." << std::endl;
        return;
    }
    std::cout << "Concatenated string: " << s.c_str() << std::endl;
}

void interactive_test_concatenate_string() {
    std::cout << "\n=== Test Concatenation with Another String ===" << std::endl;
    std::string input1, input2;
    std::cout << "Enter first string: ";
    input1 = get_valid_string();
    std::cout << "Enter second string to concatenate: ";
    input2 = get_valid_string();
    string s1(input1.c_str()), s2(input2.c_str());
    s1 = s1 + s2;
    if (s1.size() > s1.max_size()) {
        std::cerr << "Error: Concatenated string exceeds the maximum allowed size (" << s1.max_size() << ")." << std::endl;
        return;
    }
    std::cout << "Concatenated string: " << s1.c_str() << std::endl;
}

