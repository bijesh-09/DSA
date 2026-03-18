#include <stdio.h>

void iterative_fibo(int n)
{
    int a = 0, b = 1, next;
    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            next = i;
            printf("%d ", next);
        }
        else
        {
            next = a + b;
            a = b;
            b = next;
            printf("%d ", next);
        }
    }
}
int non_tailFibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return non_tailFibo(n - 1) + non_tailFibo(n - 2);
    }
}

void printNonTailFiboSeries(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", non_tailFibo(i));
    }
}

int tailFibo(int n, int a, int b)
{
    if (n == 0)
    {
        return a;
    }
    else if (n == 1)
    {
        return b;
    }
    else
    {
        return tailFibo(n - 1, b, a + b);
    }
}

void printTailFiboSeries(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tailFibo(i, 0, 1));
    }
}

int main()
{
    int number;
    printf("Enter a number to find its Fibonacci series: ");
    scanf("%d", &number);

    printf("Fibonacci series up to %d using iterative method is: ", number);
    iterative_fibo(number);
    printf("\n\n");

    printf("Fibonacci series up to %d using non-tail recursive method is: ", number);
    printNonTailFiboSeries(number);
    printf("\n\n");

    printf("Fibonacci series up to %d using tail recursive method is: ", number);
    printTailFiboSeries(number);
    printf("\n");

    return 0;
}