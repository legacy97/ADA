#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge function
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int sizes[] = {1000, 5000, 10000, 20000, 50000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int s = 0; s < numSizes; s++) {
        int N = sizes[s];
        int *arr = (int *)malloc(N * sizeof(int));

        // Generate random array
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 100000;
        }

        clock_t start = clock();
        mergeSort(arr, 0, N - 1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("N = %d, Time taken = %f seconds\n", N, time_taken);

        free(arr);
    }

    return 0;
}
