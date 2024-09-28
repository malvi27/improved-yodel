#include <stdio.h>

// Function to perform binary search in a sorted matrix
int binarySearch(int matrix[][4], int row, int col, int target) {
    int low = 0;
    int high = row * col - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int mid_element = matrix[mid / col][mid % col];

        if (mid_element == target) {
            return 1; // Element found
        } else if (mid_element < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0; // Element not found
}

int main() {
    int matrix[3][4] = {{1, 3, 5, 7},
                        {10, 11, 16, 20},
                        {23, 30, 34, 50}};
    int target = 3;

    if (binarySearch(matrix, 3, 4, target)) {
        printf("Element %d is present in the matrix.\n", target);
    } else {
        printf("Element %d is not present in the matrix.\n", target);
    }

    return 0;
}
