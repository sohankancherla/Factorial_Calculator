#include <stdio.h>
#include <stdlib.h>

// Let the program know functions exists
long long int factorial_iterative(int input);
long long int factorial_recursive(int input);

// Get the system arguments
int main(int argc, char* argv[]) {

    // Check for the proper number of argumets
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    // Assign the system argument into variable
    int input = atoi(argv[1]);

    // Check if input is a positive integer
    if (input < 0) {
        printf("Invalid input entered\n");
        printf("Input must be an integer greater than  or equal to 0");
        return 1;
    }

    // Iterative apporach
    long long int result1 = factorial_iterative(input);

    printf("Iterative Approach\n");
    if (result1 == -1) {
        printf("Result: Integer Overflow\n");
    }
    else {
        printf("Result: %lld\n", result1);
    }

    // Recursive apporach
    long long int result2 = factorial_recursive(input);

    printf("Recursive Approach\n");
    if (result1 == -1) {
        printf("Result: Integer Overflow\n");
    }
    else {
        printf("Result: %lld\n", result2);
    }

    return 0;


}

// Iterative approach method
long long int factorial_iterative(int input) {
    long long int result = 1;

    // Loop from input to 2 and multiply each number
    for (int i = input; i > 1; i--){
        result = result * i;
        // Check for integer overflow
        if (result < 0) {
            return -1;
        }
    }

    return result;
}

// Recursive approach method
long long int factorial_recursive(int input) {

    // Base case
    if (input <= 1) {
        return 1;
    }

    // Recursion
    long long int result = input * factorial_recursive(input - 1);
    
    //Check for integer overflow
    if (result < 0) {
        return -1;
    }

    return result;
}