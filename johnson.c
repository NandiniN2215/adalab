#include <stdio.h>

// Function to print the current permutation
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Function to find the largest mobile element
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobile_index = -1;

    for (int i = 0; i < n; i++) {
        int next = i + dir[i];

        if (next >= 0 && next < n) {
            if (perm[i] > perm[next] && perm[i] > mobile) {
                mobile = perm[i];
                mobile_index = i;
            }
        }
    }
    return mobile_index;
}

// Johnson-Trotter algorithm
void johnsonTrotter(int n) {
    int perm[n], dir[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = -1; // -1 means left
    }

    printPermutation(perm, n);

    while (1) {
        int mobile_index = getMobile(perm, dir, n);

        if (mobile_index == -1)
            break;

        int swap_with = mobile_index + dir[mobile_index];

        // Swap elements
        int temp = perm[mobile_index];
        perm[mobile_index] = perm[swap_with];
        perm[swap_with] = temp;

        // Swap directions
        temp = dir[mobile_index];
        dir[mobile_index] = dir[swap_with];
        dir[swap_with] = temp;

        mobile_index = swap_with;

        // Reverse direction of all elements greater than the moved one
        for (int i = 0; i < n; i++) {
            if (perm[i] > perm[mobile_index]) {
                dir[i] = -dir[i];
            }
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
