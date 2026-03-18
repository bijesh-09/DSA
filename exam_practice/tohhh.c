#include <stdio.h>

void toh_order1(int n, char dest, char src, char aux){
    int count =0;
    if (n==0)
    {
        return;
    }
    toh_order1(n-1, aux, src, dest);

    count++;
    printf("Move %d: Disk %d from %c to %c\n",count, n, src, dest);

    toh_order1(n-1, dest, aux, src);
    
}

void toh_order2(int n, char src, char aux, char dest){
    int count =0;
    if (n==0)
    {
        return;
    }
    toh_order2(n-1, src, dest, aux);

    count++;
    printf("Move %d: Disk %d from %c to %c\n",count, n, src, dest);

    toh_order2(n-1, aux, src , dest);
    
}

int main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("TOH with order: n, destination, source, auxiliary\n");
    toh_order1(n, 'C', 'A', 'B');

    printf("\nTOH with order: n, source, auxiliary, destination\n");
    toh_order2(n, 'A', 'B', 'C');

    return 0;
}
