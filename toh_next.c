#include <stdio.h>

// Counter to track moves
int count = 0;

// TOH with order: n, destination, source, auxiliary
void toh(int n, char dest, char src, char aux) {
    if (n == 0) {
        return;
    }

    // Step 1: Move n-1 disks from Source to Auxiliary
    // (In this call: src is src, aux becomes the new destination, dest is the helper)
    toh(n - 1, aux, src, dest);

    // Step 2: Move the actual disk
    count++;
    printf("Move %d: Disk %d from %c to %c\n", count, n, src, dest);

    // Step 3: Move n-1 disks from Auxiliary to Destination
    // (In this call: aux is now the source, dest is dest, src is the helper)
    toh(n - 1, dest, aux, src);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    // Calling with rods labeled 'C' (Dest), 'A' (Src), 'B' (Aux)
    toh(n, 'A', 'B', 'C');

    printf("\nTotal steps: %d\n", count);
    return 0;
}