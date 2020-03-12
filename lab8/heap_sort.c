// heap sort in to print elements in descending order
#include<stdio.h>
#include<stdlib.h>

int sorted[10];
void heapify(int* heap, int count)
{
    int i, j, k, v;
    int flag = 0;
    for(i = count / 2; i >= 1; i--)
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
            //compare the max of children with the root node
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

void delete(int* heap, int count)
{
    int index = 1;
    while(count >= 1)
    {
        //sorted[] is the final array
        sorted[index++] = heap[1];
        heap[1] = heap[count];
        count -= 1;
        heapify(heap, count);
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

    delete(heap,count);

    for(int i = 1; i <= count; i++)
    {
        printf(" %d", sorted[i]);
    }    

}