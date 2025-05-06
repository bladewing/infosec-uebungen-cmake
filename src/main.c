#include <stdio.h>
#include "calculator.h"

int main() {
    printf("Simple Calculator Application\n");
    printf("---------------------------\n");
    
    // Test addition
    int sum = add(5, 3);
    printf("5 + 3 = %d\n", sum);
    
    // Test subtraction
    int difference = subtract(10, 4);
    printf("10 - 4 = %d\n", difference);
    
    // Test multiplication
    int product = multiply(6, 7);
    printf("6 * 7 = %d\n", product);
    
    // Display last result
    printf("Last result: %d\n", get_last_result());
    
    return 0;
}