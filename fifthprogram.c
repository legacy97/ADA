#include <stdio.h>

int main() {
    int arr[100], n, i;
    int largest, secondLargest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    secondLargest = arr[0];

    // Find largest element
    for(i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Find second largest element
    secondLargest = -999999;   // small value
    for(i = 0; i < n; i++) {
        if(arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }

    printf("Second largest element = %d", secondLargest);

    return 0;
}
