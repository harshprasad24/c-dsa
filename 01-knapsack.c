#include <stdio.h>

int max(int a, int b) {
    if(a>b){
        return(a);
    }else{
        return(b);
    }
}

int knapsack(int W, int weight[], int value[], int n) {
    int arr[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (weight[i - 1] <= j)
                arr[i][j] = max(arr[i - 1][j],value[i - 1] + arr[i - 1][j - weight[i - 1]] );
            else
                arr[i][j] = arr[i - 1][j];
        }
    }
    return arr[n][W];
}

int main() {
    int n;  
    int W;  
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int value[n], weight[n];
    for (int i = 1; i <= n; i++) {
        printf("Enter the value of item %d: ", i);
        scanf("%d", &value[i]);
    }

    for (int i = 1; i <= n; i++) {
        printf("Enter the weight of item %d: ", i);
        scanf("%d", &weight[i]);
    }
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);
    int max_value = knapsack(W, weight, value, n);
    printf("The maximum value that can be obtained is: %d\n", max_value);

    return 0;
}

