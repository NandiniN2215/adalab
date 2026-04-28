#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n, i;
    clock_t start, end;
    double time_taken;


    int sizes[] = {1000, 5000, 10000, 20000, 50000};
    int num_sizes = 5;

    for (int s = 0; s < num_sizes; s++) {
        n = sizes[s];

        int *arr = (int *)malloc(n * sizeof(int));


        for (i = 0; i < n; i++) {
            arr[i] = rand() % 100000;
        }

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("N = %d, Time Taken = %f seconds\n", n, time_taken);

        free(arr);
    }

    return 0;
}
