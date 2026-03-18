#include <stdio.h>

// Function to solve Tower of Hanoi
void toh(int n, char source, char auxiliary, char destination) {
    // Base case
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    toh(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination
    toh(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    // A = source, B = auxiliary, C = destination
    toh(n, 'A', 'B', 'C');

    return 0;
}