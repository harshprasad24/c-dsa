#include<stdio.h>
int main(){
    int n;
    printf("Enter the no of elments:");
    scanf("%d",&n);

    int p[n],w[n],pw[n];

    for(int i=1;i<=n;i++){
        printf("Enter the profit ::%d",i);
        scanf("%d",&p[i]); 
    }
    for(int i=1;i<=n;i++){
        printf("Enter the weight ::%d",i);
        scanf("%d",&w[i]); 
    }
    for(int i=1;i<=n;i++){
        pw[i]=p[i]/w[i]; 
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (pw[j] > pw[j+1]) {
                int temp = pw[j];
                pw[j] = pw[j+1];
                pw[j+1] = temp;
            }
        }
    }
    int sum;
    
    for(int i=1;i<=n;i++){
        if(i<=n)
        sum=pw[i]*p[i];
        i++;
    }
    printf("The maximum value obtained is :%d",sum);
    return 0;
}

