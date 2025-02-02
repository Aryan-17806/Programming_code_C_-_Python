#include <stdio.h>
#include <stdlib.h>

// Function to search for an element in the array and print all occurrences
void searchElement(int **a, int n, int target) {
    int found = 0;
    printf("\nSearching for element %d...\n", target);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == target) {
                printf("Element %d found at index [%d][%d]\n", target, i + 1, j + 1);  // 1-based indexing
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}

// Function to swap two elements in the array
void swapElements(int **a, int n, int r1, int c1, int r2, int c2) {
    // Convert 1-based to 0-based indices
    r1--; c1--; r2--; c2--;

    if (r1 >= 0 && r1 < n && c1 >= 0 && c1 < n && r2 >= 0 && r2 < n && c2 >= 0 && c2 < n) {
        int temp = a[r1][c1];
        a[r1][c1] = a[r2][c2];
        a[r2][c2] = temp;
        printf("Swapped successfully.\n");
    } else {
        printf("Invalid indices. Swap not performed.\n");
    }
}

// Function to update an element in the array
void updateElement(int **a, int n, int r, int c, int value) {
    // Convert 1-based to 0-based indices
    r--; c--;

    if (r >= 0 && r < n && c >= 0 && c < n) {
        a[r][c] = value;
        printf("Updated successfully.\n");
    } else {
        printf("Invalid index. Update not performed.\n");
    }
}

// Function to print the array
void printArray(int **a, int n) {
    printf("\nArray elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Function to print the array in reverse order
void printReverseArray(int **a, int n) {
    printf("\nArray elements in reverse order:\n");
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Function to find duplicate elements
void findDuplicates(int **a, int n) {
    int hasDuplicates = 0;
    int freq[10001] = {0}; // Assuming elements are within 0-10000

    printf("\nDuplicate elements in the array: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (freq[a[i][j]] == 1) {
                printf("%d ", a[i][j]);
                hasDuplicates = 1;
            }
            freq[a[i][j]]++;
        }
    }

    if (!hasDuplicates) {
        printf("None");
    }
}

// Function to find max and min values
void findMaxMin(int **a, int n) {
    int max = a[0][0], min = a[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > max) max = a[i][j];
            if (a[i][j] < min) min = a[i][j];
        }
    }

    printf("\nMaximum value in the array is: %d\n", max);
    printf("Minimum value in the array is: %d\n", min);
}

int main() {
    int n;
    printf("Enter the size of the 2D array (NxN): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size. Please enter a positive value.\n");
        return 1;
    }

    // Dynamic memory allocation
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Search for an element
    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    searchElement(a, n, target);

    // Swap elements
    int r1, c1, r2, c2;
    printf("Enter the indices you want to swap (row1 col1 row2 col2 - 1-based): ");
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    swapElements(a, n, r1, c1, r2, c2);

    // Update an element
    int r, c, value;
    printf("Enter the indices you want to update and the new number (row col num - 1-based): ");
    scanf("%d %d %d", &r, &c, &value);
    updateElement(a, n, r, c, value);

    // Print the array
    printArray(a, n);

    // Print the array in reverse order
    printReverseArray(a, n);

    // Find duplicate elements
    findDuplicates(a, n);

    // Find max and min values
    findMaxMin(a, n);

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
