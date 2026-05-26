#include <stdio.h>

#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int dir;
} Element;

// Function to print the current permutation
void printPermutation(Element perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i].value);
    }
    printf("\n");
}

// Function to find the largest mobile element
int findLargestMobile(Element perm[], int n) {
    int mobileIndex = -1;
    int mobileValue = 0;

    for (int i = 0; i < n; i++) {
        if (perm[i].dir == LEFT && i > 0 && perm[i].value > perm[i - 1].value) {
            if (perm[i].value > mobileValue) {
                mobileValue = perm[i].value;
                mobileIndex = i;
            }
        }
        if (perm[i].dir == RIGHT && i < n - 1 && perm[i].value > perm[i + 1].value) {
            if (perm[i].value > mobileValue) {
                mobileValue = perm[i].value;
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

// Function to generate permutations using Johnson-Trotter
void johnsonTrotter(int n) {
    Element perm[n];

    // Initialize permutation and directions
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].dir = LEFT;
    }

    printPermutation(perm, n);

    while (1) {
        int mobileIndex = findLargestMobile(perm, n);

        if (mobileIndex == -1)
            break;

        int swapIndex = mobileIndex + perm[mobileIndex].dir;

        // Swap mobile element
        Element temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        int mobileValue = perm[swapIndex].value;

        // Reverse directions of all elements greater than mobileValue
        for (int i = 0; i < n; i++) {
            if (perm[i].value > mobileValue) {
                perm[i].dir *= -1;
            }
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
