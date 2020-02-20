#include<stdio.h>
#include<stdlib.h>
int opcount = 0;
void merge(int arr[], int beg, int mid, int end)
{
    int i = beg, j = mid+1, temp[100];
    int index = beg;

    //formation of a sorted array
    while((i <= mid) && (j <= end))
    {
        if(arr[i] > arr[j])
        {
            temp[index] = arr[j];
            j++;
        }
        else
        {
            temp[index] = arr[i];
            i++;
        }
        index++;
    }

    //for remaining elements
    while(i <= mid)
    {
        temp[index] = arr[i];
        i++;
        index++;
    }
    while(j <= end)
    {
        temp[index] = arr[j];
        j++;
        index++;
    }

    //copy the new order to the original array
    for(int k = beg; k < index; k++)
    {
        arr[k] = temp[k];
    }
}


void merge_sort(int arr[], int beg, int end)
{
    //if there are two or more elements in the array
    if(beg<end)
    {
        opcount++;
        int mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);

        //combine the two arrays
        merge(arr, beg, mid, end);

    }
}


int main()
{
    int arr[100];
    int n;
    printf("enter number of elements: \n");
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);
    
    //output
    for(int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
    printf("opcount is: %d \n", opcount);

}
