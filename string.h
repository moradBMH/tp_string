#ifndef STRING_H    // Checks if STRING_H hasn't been defined yet
#define STRING_H    // ifndef, defines STRING_H

#include <cstddef> // Defines size_t

class string {
    public:
        // Default Constructor
        string() ;

        // Copy Constructor
        string(const string& other);

        // Character Constructor; initializes a string with a single char
        string(char c);

        // Constructor from a c-style
        string(const char* cstr);

        // Destructor
        ~string();

        // Method to get the C-string chain
        const char* c_str() const;

        // Method to get the chain size
        size_t size() const;

        // Method to clear the chain
        void clear();

        //Assignment operator with one character
        string& operator=(char c);

        // Assignment operator with an other string
        string& operator=(const string& other);

        // Concatenation operator with a chain C
        string operator+(const string& other) const;

        // Method to print the chain tests
        void print() const;

    private:
        char* data_members_; // A pointer to a dynamically allocated array holding the actual characters of the string.
        size_t len_; // The length of the string
        size_t capacity_;  // The total allocated memory size for the string (max. number of characters before memory reallocation)


};

#endif //STRING_H
