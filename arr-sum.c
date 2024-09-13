#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int array[rows][cols];
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if(i==j){
                printf("Enter element for position (%d,%d): ", i, j);
                scanf("%d", &array[i][j]);
            } 
            else{
                array[i][j]=0;
            }
        }
    }
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if(i==j-1){
                array[i][j]=array[i][i]+array[j][j];
                printf("%d", &array[i][j]);
        }
    }
}
for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if(i==j-2){
                array[i][j]=array[i][i]+array[j][j];
                printf("%d", &array[i][j]);
        }
    }
}
    printf("The 2D array is:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}


