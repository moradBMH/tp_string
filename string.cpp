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


////METHODS

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

// Alias for size()
size_t string::length() const {
    return size();
}

//Get the maximal potential size
size_t string::max_size() const {
    return 100;
}

//Resize the string
void string::resize(size_t new_size, char fill_char) {
    if (new_size > max_size()) {
        std::cerr << "Error: New size exceeds maximum size." << std::endl;
        return;
    }

    char* new_data = new char[new_size + 1]; // +1 for null terminator
    size_t copy_length = (new_size < len_) ? new_size : len_;

    for (size_t i = 0; i < copy_length; ++i) {
        new_data[i] = data_members_[i];
    }

    for (size_t i = copy_length; i < new_size; ++i) {
        new_data[i] = fill_char;
    }

    new_data[new_size] = '\0';

    delete[] data_members_;
    data_members_ = new_data;
    len_ = new_size;
    capacity_ = new_size + 1;
}


////ASSIGNEMENT OPERATORS

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


////CONCATENATION OPERATORS

// Concatenation operator with a string and a character (string + char)
string string::operator+(const char c) const {
    // Calculate the total new length for the concatenation
    size_t new_len = this->size() + 1;  // Add 1 for the new character

    // Allocate memory for the new concatenated string
    size_t new_capacity = new_len + 1;  // Include space for the null terminator
    char* new_data = new char[new_capacity];

    // Copy the current string (this) into the new buffer
    const char* this_cstr = this->c_str();  // Get the C-string of the current string
    for (size_t i = 0; i < this->size(); ++i) {
        new_data[i] = this_cstr[i];  // Copy each character from the current string
    }

    // Add the new character at the end
    new_data[this->size()] = c;

    // Null-terminate the string
    new_data[new_len] = '\0';

    // Create the result string and assign the new data to it
    string result;
    result.data_members_ = new_data;
    result.len_ = new_len;
    result.capacity_ = new_capacity;

    return result;  // Return the concatenated string
}

// Concatenation operator with a string and a C-string (string + const char*)
string string::operator+(const char* cstr) const {
    // Calculate the total new length for the concatenation
    size_t new_len = this->size();  // Start with the length of the current string

    // Calculate the length of the C-string (const char*)
    size_t cstr_len = 0;
    while (cstr[cstr_len] != '\0') {
        ++cstr_len;
    }

    new_len += cstr_len;  // Add the length of the C-string to the total length

    // Allocate memory for the new concatenated string
    size_t new_capacity = new_len + 1;  // Include space for the null terminator
    char* new_data = new char[new_capacity];

    // Copy the current string (this) into the new buffer
    const char* this_cstr = this->c_str();  // Get the C-string of the current string
    for (size_t i = 0; i < this->size(); ++i) {
        new_data[i] = this_cstr[i];  // Copy each character from the current string
    }

    // Copy the C-string (cstr) into the new buffer
    size_t i = this->size();  // Start copying at the point after the current string
    while (*cstr) {
        new_data[i++] = *cstr++;  // Copy each character from the C-string
    }

    // Null-terminate the string
    new_data[new_len] = '\0';

    // Create a string result with the new data and length
    string result;
    result.data_members_ = new_data;
    result.len_ = new_len;
    result.capacity_ = new_capacity;

    return result;  // Return the concatenated string
}

// Concatenation operator with another string
string string::operator+(const string& other) const {
    return *this + other.c_str();
}
