#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
    a= abs(a);
    b= abs(b);
    if (a>b)
    {
        
        if (b==0)
        {
            return a;
        }
        else{
            return gcd(b, a%b);
        }
    }
    else{
        if (a==0)
        {
            return b;
        }
        else{
            return gcd(a, b%a);
        }
    }
    
}

int main(){
    int a , b;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &a, &b);

    int result = gcd(a, b);
    
    printf("GCD of %d and %d is %d\n", a, b, result);

    return 0;
}