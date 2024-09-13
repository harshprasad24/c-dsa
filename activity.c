#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int m, n, i, j;

    printf("Enter the number of input: ");
    scanf("%d", &m);
    printf("Enter the number of output: ");
    scanf("%d", &n);
    
    int arr[m][n]; 
    
    printf("Enter elements of the %d x %d array:\n", m, n);
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(i = 0; i < m; i++) {
        bubbleSort(arr[i], n);
    }
    
    printf("Sorted 2D array:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
