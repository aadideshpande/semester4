//quick sort
#include<stdio.h>
#include<stdlib.h>
int opcount = 0;
int arr[100];

void print(int m, int n)
{
    printf("sorted array is: \n");
    for(int i = m; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
void swap(int x, int y)
{

    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int l, int r)
{

    if(r == (l + 1))
    {
        if(arr[l] > arr[r])
        {
            swap(l, r);
            return 0;
        }
    }
    int pivot = arr[l];
    int i = l, j = r + 1;
    while(i <= j)
    {
        do
        {
            i++;
            opcount++;
        } while (pivot > arr[i]);
        do
        {
            j--;
            opcount++;
        } while (pivot < arr[j]);
        if(i < j){swap(i, j);}
    }
    //swap(i, j);
    swap(l, j);
    return j;
}

void quick(int l,int r)
{

    if(l < r)
    {
        int s = partition(l,r);
        //printf("s is: %d \n", s);
        quick(l,s - 1);
        quick(s + 1, r);
    }
}

int main()
{
    int n;
    printf("enter length of the array: \n");
    scanf(" %d", &n);

    printf("enter the elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }
    quick(0,n - 1);
    print(0, n);
    printf("opcount is: %d \n", opcount);

}