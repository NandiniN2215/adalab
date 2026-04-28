#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // choosing last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;
    clock_t start, end;
    double time_taken;

    // Different input sizes
    int sizes[] = {1000, 5000, 10000, 20000, 50000};
    int num_sizes = 5;

    for (int s = 0; s < num_sizes; s++) {
        n = sizes[s];

        int *arr = (int *)malloc(n * sizeof(int));

        // Generate random elements
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 100000;
        }

        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("N = %d, Time Taken = %f seconds\n", n, time_taken);

        free(arr);
    }

    return 0;
}
