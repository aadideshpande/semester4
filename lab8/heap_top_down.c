// heap construction using TOP DOWN approach
#include<stdio.h>
#include<stdlib.h>

void heapify(int* heap, int count)
{
    int i, j, k, v;
    int flag = 0;
    for(i = 1; i <= (count / 2); i++)
    {
        k = i;
        v = heap[k];
        flag = 0;
        while( !flag && 2*k <= count)
        {
            j = 2 * k;
            // does the node have two children?
            if(j < count)
            {
                //find the max from the two nodes
                if(heap[j] < heap[j + 1]){j += 1;}
            }
            //comapre the max of children with the root node
            if(v >= heap[j])
            {
                flag = 1;
            }
            else    //if any of the children are greater, then replace
            {
                heap[k] = heap[j];
                k = j;
            }
        }
        heap[k] = v;
    }
}

int main()
{
    int heap[10];
    int count;
    printf("enter the no. of elements: \n");
    scanf(" %d", &count);
    printf("enter the elements: \n");
    for(int i = 1; i <= count; i++)
    {
        scanf(" %d", &heap[i]);
    }        
    heapify(heap, count);
    for(int i = 1; i <= count; i++)
    {
        printf(" %d", heap[i]);
    }    

}