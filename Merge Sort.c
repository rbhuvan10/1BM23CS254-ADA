#include <stdio.h>
#include <time.h> 
void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int leftArr[size1], rightArr[size2];

    for(int i = 0; i < size1; i++) {
        leftArr[i] = arr[left + i];
    }
    for(int i = 0; i < size2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while(i < size1 && j < size2) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        }
        else {
            arr[k++] = rightArr[j++];
        }
    }

    while(i < size1) {
        arr[k++] = leftArr[i++];
    }

    while(j < size2) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    clock_t start, end;
    start = clock();
    int arr[] = {5,2,7,9,10,15,3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array: ");
    for(int i = 0; i < arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    mergeSort(arr, 0, arrSize - 1);
    printf("\nSorted Array: ");
    for(int i = 0; i < arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    end = clock();
    printf("\nTime take is %f in seconds", ((double)(end-start))/CLOCKS_PER_SEC);
}

Output:
Original Array: 5, 2, 7, 9, 10, 15, 3, 
Sorted Array: 2, 3, 5, 7, 9, 10, 15,
Time take is 0.001000 in seconds

Original Array: 3, 8, 2, 1, 15, 9, 11, 4, 14, 6, 10, 3, 7, 12, 5, 
Sorted Array: 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15,
Time take is 0.001000 in seconds
