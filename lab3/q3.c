#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("enter the number of elements");
    scanf("%d",&n);
    char* arr =(char*)calloc( n, sizeof(char));

    printf("enter the numbers ");
    for(int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }

    int* power_set = (char *)calloc(n, sizeof(char));



}