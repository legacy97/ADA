#include <stdio.h>
#include <stdlib.h>   // for rand()
#include <time.h>     // for clock()

// Heapify function
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    // Different input sizes to test
    int sizes[] = {5000, 10000, 15000, 20000, 25000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL)); // Seed random generator

    printf("Size\tTime (seconds)\n");
    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int arr[n];

        // Generate random integers
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100000;

        clock_t start = clock();
        heapSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, time_taken);
    }

    return 0;
}
