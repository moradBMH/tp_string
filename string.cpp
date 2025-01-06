#include "string.h"

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

// Alias for size()
size_t string::length() const {
    return size();
}

//Get the maximal potential size
size_t string::max_size() const {
    return 100;
}

// Get the allocated capacity
size_t string::capacity() const {
    return capacity_;
}

// Indicates if the string object is empty or not
bool string::empty() const {
    return len_ == 0; // True if length is zero
}

// Resets the string to be empty
void string::clear() {
    delete[] data_members_;  // Frees the current allocated memory
    data_members_ = new char[1];  // Allocates new memory for an empty string
    data_members_[0] = '\0';  // Ensures the string is empty (null-terminated)
    len_ = 0;  // Sets length to 0
    capacity_ = 1;  // Resets the capacity to 1
}

//Resize the string
void string::resize(size_t new_size, char fill_char) {

    // Allocate new memory for the resized string (+1 for the null terminator)
    char* new_data = new char[new_size + 1];

    // Determine the number of characters to copy (either the new size or the current length, whichever is smaller)
    size_t copy_length = (new_size < len_) ? new_size : len_;

    // Copy the original string's characters to the new memory
    for (size_t i = 0; i < copy_length; ++i) {
        new_data[i] = data_members_[i];
    }

    // If the new size is larger, fill the remaining space with the specified fill character
    for (size_t i = copy_length; i < new_size; ++i) {
        new_data[i] = fill_char;
    }

    // Ensure the string is properly null-terminated
    new_data[new_size] = '\0';

    // Delete the old string data and point to the new memory
    delete[] data_members_;
    data_members_ = new_data;

    // Update the string's length and capacity
    len_ = new_size;
    capacity_ = new_size + 1; // +1 for the null terminator
}

// Reserve space in memory for the string to accommodate more characters
void string::reserve(size_t new_capacity) {
    // If the requested capacity is smaller than or equal to the current capacity, no need to change
    if (new_capacity <= capacity_) return;

    // Allocate new memory with the desired capacity
    char* new_data = new char[new_capacity];

    // Copy the original string's characters to the new memory
    for (size_t i = 0; i < len_; ++i) {
        new_data[i] = data_members_[i];
    }

    // Ensure the string is properly null-terminated
    new_data[len_] = '\0';

    // Delete the old string data and point to the new memory
    delete[] data_members_;
    data_members_ = new_data;

    // Update the string's capacity
    capacity_ = new_capacity;
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

// Assignment operator with a Cstring
string& string::operator=(const char* cstr) {
    // Free previously allocated memory
    delete[] data_members_;

    // Calculate the length of the C-string manually (without std::strlen)
    size_t new_len = 0;
    while (cstr[new_len] != '\0') {
        ++new_len;
    }

    // Allocate memory for the new C-string + null terminator
    capacity_ = new_len + 1;
    data_members_ = new char[capacity_];

    // Copy the content of the C-string into the new memory
    for (size_t i = 0; i < new_len; ++i) {
        data_members_[i] = cstr[i];
    }
    data_members_[new_len] = '\0'; // Add the null terminator at the end

    // Update the length of the string
    len_ = new_len;

    return *this; // Return the current object
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
string string::operator+(char c) const {
    string result(*this);
    result.resize(len_ + 1);
    result.data_members_[len_] = c;
    return result;
}

// Concatenation operator with a string and a C-string (string + const char*)
string string::operator+(const char* cstr) const {
    // Calculate the new length manually (sum of current string length and C-string length)
    size_t cstr_len = 0;
    while (cstr[cstr_len] != '\0') {
        ++cstr_len;
    }
    size_t new_len = len_ + cstr_len;

    // Create a new string to hold the concatenated result
    string result;
    result.reserve(new_len + 1);  // Reserve enough space for the new string plus the null terminator

    // Copy the content of the current string into the result string
    for (size_t i = 0; i < len_; ++i) {
        result.data_members_[i] = data_members_[i];
    }

    // Append the characters from the C-string into the result string
    for (size_t i = 0; i < cstr_len; ++i) {
        result.data_members_[len_ + i] = cstr[i];
    }

    // Null-terminate the resulting string
    result.data_members_[new_len] = '\0';

    // Update the length of the resulting string
    result.len_ = new_len;

    return result; // Return the concatenated string
}

// Concatenation operator with another string
string string::operator+(const string& other) const {
    return *this + other.c_str();
}
