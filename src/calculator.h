#ifndef CALCULATOR_H
#define CALCULATOR_H

// Last operation result
extern int last_result;

// Basic arithmetic operations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

// Get the result of last operation
int get_last_result();

#endif // CALCULATOR_H