#include<stdio.h>
#include<math.h>
int main(){
    int m,sum=0,median, temp;
    printf("enter the size of array");
    scanf("%d",&m);
    int arr[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }
    for( int i=0; i<m ;i++){
        for(int j=0;j<m;j++){
            if(arr[j] > arr [i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

            }
        }
    }
    if(m % 2==0)
    {
        median = (arr[(m-1)/2] +arr[(m+1)/2])/2;
    }
    else{
        median = arr[m/2];
    }
    printf("The median is %d",median);
    return 0;
}