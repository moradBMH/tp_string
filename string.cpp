#include "string.h"
#include <iostream>

// Default constructor
string::string() : data_members_(new char[1]), len_(0), capacity_(1) {
    data_members_[0] = '\0';  // Initializes the string as empty (null-terminated)
}


// Copy constructor
string::string(const string& other) : data_members_(new char[other.capacity_]), len_(other.len_), capacity_(other.capacity_) {
    // Manually copying each character from the other string into this string's data
    for (size_t i = 0; i < other.len_; ++i) {
        data_members_[i] = other.data_members_[i];
    }
    data_members_[len_] = '\0';  // Ensure the string is null-terminated
}

//Character Constructor
string::string(char c) : data_members_(new char[2]), len_(1), capacity_(2) {
  data_members_[0] = c; //Assign the character
  data_members_[1] = '\0'; //Assign the null_terminator
}


// Constructor from a C-style string (const char*)
string::string(const char* cstr) {
    if (cstr) {
        // Calculate the length of the C-string
        len_ = 0;
        while (cstr[len_] != '\0') {
            ++len_;
        }
        capacity_ = len_ + 1;  // Capacity is length + 1 for the null-terminator
        data_members_ = new char[capacity_];  // Allocate memory for the string + null terminator
        // Copy the C-string to the object's data_members_
        for (size_t i = 0; i < len_; ++i) {
            data_members_[i] = cstr[i];
        }
        data_members_[len_] = '\0';  // Null-terminate the string
    } else {
        // If the provided C-string is nullptr, create an empty string
        data_members_ = new char[1];
        data_members_[0] = '\0';
        len_ = 0;
        capacity_ = 1;
    }
}


// Destructor
string::~string() {
    delete[] data_members_;  // Free the dynamic memory
}


// get the C-string representation of the string object
const char* string::c_str() const {
    return data_members_;  // Returns the character array (C-string)
}


// Get the length of the string (not including the null terminator)
size_t string::size() const {
    return len_;  // Returns the length of the string
}


// Resets the string to be empty
void string::clear() {
    delete[] data_members_;  // Frees the current allocated memory
    data_members_ = new char[1];  // Allocates new memory for an empty string
    data_members_[0] = '\0';  // Ensures the string is empty (null-terminated)
    len_ = 0;  // Sets length to 0
    capacity_ = 1;  // Resets the capacity to 1
}

// Assignment operator with a single character
string& string::operator=(char c) {
    delete[] data_members_;  // Deallocates the current memory
    data_members_ = new char[2];  // Allocates new memory for a single character and the null terminator
    data_members_[0] = c;  // Assigns the character
    data_members_[1] = '\0';  // Null-terminates the string
    len_ = 1;  // Sets the length to 1
    capacity_ = 2;  // Sets capacity to 2 (1 character + null terminator)
    return *this;  // Returns the current object to allow for chaining of assignments
}


// Assignment operator with another string (copy assignment)
string& string::operator=(const string& other) {
    if (this != &other) {  // Prevent self-assignment
        delete[] data_members_;  // Deallocate current memory

        // Allocate new memory based on the other string's length and capacity
        capacity_ = other.capacity_;
        len_ = other.len_;
        data_members_ = new char[capacity_];

        // Copy the characters from the other string
        for (size_t i = 0; i < len_; ++i) {
            data_members_[i] = other.data_members_[i];
        }
        data_members_[len_] = '\0';  // Ensure the string is null-terminated
    }

    return *this;  // Return *this to allow for chaining of assignments
}


// Concatenation operator with a C-string
string string::operator+(const string& other) const {
    // Calculate the total new length for the concatenation
    size_t new_len = len_ + other.len_;  // Total length is the sum of both string lengths

    // Allocate memory for the new concatenated string
    size_t new_capacity = new_len + 1;  // Include space for the null terminator
    char* new_data = new char[new_capacity];

    // Copy the current string (this object) to the new buffer
    for (size_t i = 0; i < len_; ++i) {
        new_data[i] = data_members_[i];
    }

    // Copy the other string (other) into the new buffer
    for (size_t i = 0; i < other.len_; ++i) {
        new_data[len_ + i] = other.data_members_[i];
    }

    // Add the null terminator at the end
    new_data[new_len] = '\0';

    // Create the result string and assign the new data to it
    string result;
    result.data_members_ = new_data;
    result.len_ = new_len;
    result.capacity_ = new_capacity;

    return result;  // Return the concatenated string
}
