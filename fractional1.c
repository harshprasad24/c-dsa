#include <stdio.h>


double fractionalKnapsack(int W, int value[], int weight[], int n) {
    double totalValue = 0.0;  
    int currentWeight = 0;    

    
    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= W) {
            
            currentWeight += weight[i];
            totalValue += value[i];
        } else {
            
            int remainingWeight = W - currentWeight;
            totalValue += value[i] * ((double) remainingWeight / weight[i]);
            break; 
        }
    }

    return totalValue;
}


int main() {
    int n, W;

    
    printf("Enter number of items: ");
    scanf("%d", &n);

    int value[n], weight[n];

    
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &value[i], &weight[i]);
    }

    
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    
    double maxValue = fractionalKnapsack(W, value, weight, n);
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    return 0;
}