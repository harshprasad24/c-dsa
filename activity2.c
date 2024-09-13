#include<stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }                         
}
int main(){
    int i,j,m,n;
    printf("Enter the number of row: ");
    scanf("%d", &m);
    printf("Enter the number of column: ");
    scanf("%d", &n);
    int arr[m][n]; 
    printf("Enter elements of the %d x %d array: \n", m, n);
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(i==0){
                printf("Enter the input number (%d,%d):",i,j);
                scanf("%d", &arr[i][j]); 
            }else{
                printf("Enter the output number (%d,%d):",i,j);
                scanf("%d", &arr[i][j]);
            }
        }
    }
    for(i = 0; i < m; i++) {
    bubbleSort(arr[i], n);
    }
    printf("Sorted 2D array:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);                                                                                                                                arr[0][0]=2;arr[0][1]=1;
        }
        printf("\n");
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
    for(int c = 0; c < n; c++){
        if(arr[0][c+1]==arr[1][c]){
            printf("(%d,%d)",arr[0][c+1]);
        }
    }
  }
}
    return 0;
}