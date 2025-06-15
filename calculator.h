// structure for the calculator program
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <stdexcept> 

// main operator functions, add, subtract, multiply, divide 

class Calculator {
// Private members can be added if needed

private:
    // double lastResult;
    double lastResult = 0.0; // to store the last result if needed, like for chaining operations
    // TODO: history of operations, lets say up to 10 operations but not yet 
    // a dynamic array or vector could be used for history, but not needed for basic functionality
    double currentResult = 0.0; // to store the current result for operations

    OperationHistory history; // to hold operation history if needed
    // could implement a fraction data type for more complex operations
    // Function to add two numbers
    
    double add(double a, double b) {
        return a + b;
    }

    // Function to subtract two numbers
    double subtract(double a, double b) {
        return a - b;
    }

    // Function to multiply two numbers
    double multiply(double a, double b) {
        return a * b;
    }

    // Function to divide two numbers
    double divide(double a, double b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return a / b;
    }
    // need to figure out if this root function is efficient because of the 1.0 / b in particular 
    double root(double a, double b) {
        if (a < 0 || b <= 0) {
            throw std::invalid_argument("Invalid input for root operation.");
        }
        return pow(a, 1.0 / b);
    }
    double power(double a, double b) {
        return pow(a, b);
    }

public:
    // Constructor
    Calculator() {}

    // Destructor
    ~Calculator() {
        // there's nothing to really clean, 
    }

    // Public interface for operations
    double operation(const std::string& op, double a, double b) {
        switch op{
        case '+': // add
            currentResult = add(a, b);
            break;
        case '-': // subtract
            currentResult = subtract(a, b);
            break;
        case '*':   
            currentResult = multiply(a, b);
            break;
        case '/': // divide 
            currentResult = divide(a, b);
            break;
        case '^': // power
            currentResult = power(a, b);
            break;
        case '//': // root operation
            currentResult = root(a, b);
            break;
        }

        lastResult = currentResult; // store the last result for chaining
        return currentResult; // return the result of the operation
    }
    double getLastResult() const {
        return lastResult; //for chaining operations
    }
    
    double getCurrentResult() const {
        return currentResult; // the current result
    } 
    // so that the logic is handled purely in the class


};

#endif
