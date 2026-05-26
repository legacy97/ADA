#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest = arr[0];
    int secondSmallest = arr[0];

    // Find smallest element
    for(i = 1; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    // Find second smallest element
    secondSmallest = 999999;   // large value
    for(i = 0; i < n; i++) {
        if(arr[i] > smallest && arr[i] < secondSmallest) {
            secondSmallest = arr[i];
        }
    }

    printf("Second smallest element = %d\n", secondSmallest);

    return 0;
}
