#include <stdio.h>

int main() {
    int n = 4; 

    for(int k = 0; k < rows; k++) {
        for(int l = 0; l < k; l++) {
            printf(" ");
        }
        for(int m = 0; m < rows - k; m++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
