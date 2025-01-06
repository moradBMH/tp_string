#include "string_tests.cpp"

int main() {
    // ======= INTERACTIVE TESTS =======
    test_default_constructor();
    test_copy_constructor();
    test_char_constructor();
    test_cstr_constructor();
    test_destructor();
    test_clear();
    test_resize_increase();
    test_resize_decrease();
    test_reserve();
    test_assign_cstr();
    test_assign_string();
    test_assign_char();
    test_concatenate_char();
    test_concatenate_cstr();
    test_concatenate_string();
    test_equality_operator();
    test_max_size();
    // ======= NON INTERACTIVE TESTS =======
    interactive_test_default_constructor();
    interactive_test_copy_constructor();
    interactive_test_char_constructor();
    interactive_test_cstr_constructor();
    interactive_test_clear();
    interactive_test_resize_increase();
    interactive_test_resize_decrease();
    interactive_test_concatenate_char();
    interactive_test_concatenate_cstr();
    interactive_test_concatenate_string();
    return EXIT_SUCCESS;
}