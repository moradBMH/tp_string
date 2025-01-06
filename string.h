#ifndef STRING_H    // Checks if STRING_H hasn't been defined yet
#define STRING_H    // if not def, defines STRING_H

#include <cstddef> // Defines size_t

class string {
    public:

        //CONSTRUCTORS
        string(); // Default Constructor
        string(const string& other); // Copy Constructor
        string(char c); // Character Constructor
        string(const char* cstr); // Constructor from a C-style string

        //DESTRUCTOR
        ~string();

        //METHODS
        const char* c_str() const; // Get the C-string representation
        size_t size() const; // Get the current size of the string
        size_t length() const; // Alias for size()
        size_t max_size() const; // Get the maximum potential size
        size_t capacity() const;              // Returns the current allocated capacity
        bool empty() const;
        void reserve(size_t new_capacity);    // Reserves memory for a specified capacity
        void resize(size_t new_size, char fill_char = '\0'); // Resize the string
        void clear(); // Clear the string

        //ASSIGNMENT OPERATORS
        string& operator=(char c); // Assign a single character
        string& operator=(const string& other); // Assign another string
        string& operator=(const char* cstr); // Assigns a C-string to the string

        //CONCATENATION OPERATORS
        string operator+(const char c) const; // Concatenates a single character
        string operator+(const char* cstr) const; // Concatenates a C-string
        string operator+(const string& other) const; // Concatenates another string object

        // Method to print the chain tests
        void print() const;


    private:

        char* data_members_; // A pointer to a dynamically allocated array holding the actual characters of the string.
        size_t len_; // The length of the string
        size_t capacity_;  // The total allocated memory size for the string (max. number of characters before memory reallocation)

};

#endif //STRING_H
