#include <stdio.h>


int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        
        if (arr[mid] == key) {
            return mid;
        }
        
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        
        else {
            high = mid - 1;
        }
    }
    
    
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 72;
    
    int result = binarySearch(arr, size, key);
    if (result != -1) {
        printf("Element %d is present at index %d.\n", key, result);
    } else {
        printf("Element %d is not present in the array.\n", key);
    }
    
    return 0;
}