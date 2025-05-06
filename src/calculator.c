#include "calculator.h"

// Global variable to store the last result
int last_result = 0;

// Addition operation
int add(int a, int b) {
    last_result = a + b;
    return last_result;
}

// Subtraction operation
int subtract(int a, int b) {
    last_result = a - b;
    return last_result;
}

// Multiplication operation
int multiply(int a, int b) {
    last_result = a * b;
    return last_result;
}

// Getter for last result
int get_last_result() {
    return last_result;
}