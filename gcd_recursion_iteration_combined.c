#include <stdio.h>
#include <time.h> // Required for time functions

int findGCD_recursion(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD_recursion(b, a % b);
}
int findGCD_iteration(int a, int b) {
    while (b!=0)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
    
}

int main() {
    int num1 , num2 ;

    printf("Enter two numbers to find GCD with greater no. 1st: ");
    scanf("%d %d", &num1, &num2);
    
    // 1. Declare variables to store the start and end ticks
    clock_t startRecursion, endRecursion;
    double cpu_time_usedRecursion;

    // 2. Record the starting clock tick
    startRecursion = clock();

    int resultRecursion = findGCD_recursion(num1, num2);

    // 3. Record the ending clock tick
    endRecursion = clock();

    // 4. Calculate total time: (End - Start) / CLOCKS_PER_SEC
    cpu_time_usedRecursion = ((double) (endRecursion - startRecursion)) / CLOCKS_PER_SEC;

    printf("The GCD of %d and %d using recursion is: %d\n", num1, num2, resultRecursion);
    printf("Execution time of recursion: %f seconds\n", cpu_time_usedRecursion);

    
    // iteration 
    clock_t startIteration, endIteration;
    double cpu_time_usedIteration;

    // 2. Record the starting clock tick
    startIteration = clock();

    int resultIteration = findGCD_iteration(num1, num2);

    // 3. Record the ending clock tick
    endIteration = clock();

    // 4. Calculate total time: (End - Start) / CLOCKS_PER_SEC
    cpu_time_usedIteration = ((double) (endIteration - startIteration)) / CLOCKS_PER_SEC;

    printf("The GCD of %d and %d using recursion is: %d\n", num1, num2, resultIteration);
    printf("Execution time of recursion: %f seconds\n", cpu_time_usedIteration);
    
    return 0;
}