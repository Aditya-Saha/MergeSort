#include <stdio.h>

void merge(int arr[], int lb, int mid, int ub);
void mergeSort(int arr[], int lb, int ub);
void printArray(int arr[], int size);

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}

void merge(int arr[], int lb, int mid, int ub) {
    int i, j, k;
    
    // Create temporary arrays
    int temp[ub - lb + 1];

    i = lb;
    j = mid + 1;
    k = lb;
    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements
    if(i > mid) {
        while (j <= ub) {
            temp[k] = arr[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    //copy temp to original array
    k = lb;
    while(k <= ub) {
        arr[k] = temp[k];
        k++;
    }

}

void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        // Same as (lb + ub) / 2, but avoids overflow for large lb and ub
        int mid = lb + (ub - lb) / 2;

        // Sort first and second halves
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);

        // Merge the sorted halves
        merge(arr, lb, mid, ub);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
