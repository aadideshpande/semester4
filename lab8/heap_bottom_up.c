// heap construction using BOTTOM UP approach
#include<stdio.h>
#include<stdlib.h>

void heapify(int* heap, int count)
{
    int i, j, k, v;
    int flag = 0;
    // property of heaps: all parents are from 1 to floor(count / 2)
    for(i = count / 2; i >= 1; i--)
    {
        // k is the index of the parent
        k = i;
        v = heap[k];
        flag = 0;
        while( !flag && 2*k <= count)
        {
            // j is the index of the left child of the selected parent
            j = 2 * k;

            //if the parent has two child nodes:
            if(j < count)
            {
                //compare between the two children to get the maximum
                if(heap[j] < heap[j + 1]){j += 1;}
            }
            if(v >= heap[j])
            {
                // if parent value >= max(children), no swapping is required
                flag = 1;
            }
            else
            {
                //now, the parent node has been changed
                heap[k] = heap[j];
                k = j;  // we'll have to again perform the operations for all the lower nodes
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
    
    //input
    for(int i = 1; i <= count; i++)
    {
        scanf(" %d", &heap[i]);
    }        
    
    heapify(heap, count);
    
    //output
    for(int i = 1; i <= count; i++)
    {
        printf(" %d", heap[i]);
    }    

}