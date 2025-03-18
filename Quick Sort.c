#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    
    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) i++;
        while (arr[j] > pivot && j >= low + 1) j--;
        if (i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    clock_t start, end;
    start = clock();
    
    int arr[] = {3, 8, 2, 1, 15, 9, 11, 4, 14, 6, 10, 3, 7, 12, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    
    quickSort(arr, 0, arrSize - 1);
    
    printf("\nSorted Array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    
    end = clock();
    printf("\nTime taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    return 0;
}

Output:
Original Array: 3, 8, 2, 1, 15, 9, 11, 4, 14, 6, 10, 3, 7, 12, 5, 
Sorted Array: 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15,
Time taken: 0.000000 seconds
