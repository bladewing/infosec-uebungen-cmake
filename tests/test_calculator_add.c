#include <stdio.h>
#include "../src/calculator.h"

// Simple test function to verify the addition functionality
int test_addition() {
    // Test case 1: Basic addition of positive numbers
    if (add(5, 3) != 8) {
        fprintf(stderr, "Error: 5 + 3 should equal 8\n");
        return 0;
    }
    
    // Test case 2: Addition with zero
    if (add(10, 0) != 10) {
        fprintf(stderr, "Error: 10 + 0 should equal 10\n");
        return 0;
    }
    
    // Test case 3: Addition with negative numbers
    if (add(-5, -7) != -12) {
        fprintf(stderr, "Error: -5 + (-7) should equal -12\n");
        return 0;
    }
    
    // Test case 4: Addition where one number is negative
    if (add(8, -3) != 5) {
        fprintf(stderr, "Error: 8 + (-3) should equal 5\n");
        return 0;
    }
    
    // Test case 5: Check if last_result is updated correctly
    add(7, 6);
    if (get_last_result() != 13) {
        fprintf(stderr, "Error: last_result should be 13 after adding 7 + 6\n");
        return 0;
    }
    
    // All tests passed
    return 1;
}

int main() {
    if (test_addition()) {
        printf("All addition tests passed!\n");
        return 0;  // Success
    } else {
        fprintf(stderr, "Addition tests failed!\n");
        return 1;  // Failure
    }
}