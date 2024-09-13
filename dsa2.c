#include<stdio.h>
int main(){
    int m,n,sum=0,temp;
    printf("enter the row and collumn of array");
    scanf("%d%d",&m,&n);
    int arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    int arr2[m][n];
    for( int i=0; i<m ;i++){
        for(int j=0;j<m;j++){
            {
                arr2[i][j]=arr[j][i];
                printf("%d\t",arr2[i][j]);
            }
            printf("\n");
        }
}
return 0;
}