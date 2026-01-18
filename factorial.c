// #include <stdio.h>
// #include <time.h>

// int main()
// {
//     long double n, fact = 1;
//     clock_t start, end;
//     long double time_taken;

//     printf("Enter a number: ");
//     scanf("%d", &n);

//     start = clock(); // start time

//     for (int i = 1; i <= n; i++)
//     {
//         fact = fact * i;
//     }

//     end = clock(); // end time

//     time_taken = ((long double)(end - start)) / CLOCKS_PER_SEC;

//     printf("Factorial = %d\n", fact);
//     printf("Execution Time = %f seconds\n", time_taken);

//     return 0;
// }

#include <stdio.h>
#include <time.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int n;
    clock_t start, end;
    double time_taken;

    printf("Enter a number: ");
    scanf("%d", &n);

    start = clock();   // start time

    int result = factorial(n);

    end = clock();     // end time

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Factorial = %d\n", result);
    printf("Execution Time = %f seconds\n", time_taken);

    return 0;
}