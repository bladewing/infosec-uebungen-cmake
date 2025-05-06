#include <stdio.h>
#include "../src/calculator.h"

// Simple test function to verify the multiplication functionality
int test_multiplication() {
    // Test case 1: Basic multiplication of positive numbers
    if (multiply(4, 5) != 20) {
        fprintf(stderr, "Error: 4 * 5 should equal 20\n");
        return 0;
    }
    
    // Test case 2: Multiplication with zero
    if (multiply(10, 0) != 0) {
        fprintf(stderr, "Error: 10 * 0 should equal 0\n");
        return 0;
    }
    
    // Test case 3: Multiplication with negative numbers
    if (multiply(-3, -4) != 12) {
        fprintf(stderr, "Error: -3 * (-4) should equal 12\n");
        return 0;
    }
    
    // Test case 4: Multiplication where one number is negative
    if (multiply(5, -2) != -10) {
        fprintf(stderr, "Error: 5 * (-2) should equal -10\n");
        return 0;
    }
    
    // Test case 5: Check if last_result is updated correctly
    multiply(6, 7);
    if (get_last_result() != 42) {
        fprintf(stderr, "Error: last_result should be 42 after multiplying 6 * 7\n");
        return 0;
    }
    
    // All tests passed
    return 1;
}

int main() {
    if (test_multiplication()) {
        printf("All multiplication tests passed!\n");
        return 0;  // Success
    } else {
        fprintf(stderr, "Multiplication tests failed!\n");
        return 1;  // Failure
    }
}