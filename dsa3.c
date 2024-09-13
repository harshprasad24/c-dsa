#include<stdio.h>
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
void createArray(struct myArray * a, int tsize ,int usize ){
    (*a).total_size = tsize;
}