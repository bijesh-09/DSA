#include<stdio.h>

void iterative_fact(int n){
    int fact =1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    printf("Factorial of %d using iterative method is: %d\n", n, fact);
    
}

int non_tailFact(int n){
    if (n==1)
    {
        return 1;
    }
    else{
        return n * non_tailFact(n-1);
    }
    
}

int tailFact(int n, int acc){
    if (n==1)
    {
        return acc;
    }
    else{
        return tailFact(n-1, n*acc);
    }
    
}

int tailSum(int n, int acc){
    if (n==1)
    {
        return n+acc;
    }
    else{
        return tailSum(n-1, n+acc);
    }
    
}

int main(){
    int number;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);

    iterative_fact(number);
    printf("Factorial of %d using non-tail recursive method is: %d\n", number, non_tailFact(number));
    printf("Factorial of %d using tail recursive method is: %d\n", number, tailFact(number,1));
    printf("Sum of first %d natural numbers using tail recursive method is: %d\n", number, tailSum(number,0));

    return 0;
}