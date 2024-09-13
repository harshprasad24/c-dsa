#include <stdio.h>
#include <limits.h>

int main() {
    int n,i,j;

    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int p[n + 1];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    return 0;
}