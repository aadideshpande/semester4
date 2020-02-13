#include <stdio.h>
#include <stdlib.h>

void taposort(int adj[][100], int v)
{
    int n = v;
    int val[100];

    for (int i = 0; i < v; i++)
        val[i] = i;
   
    for(int k=0;k<n;k++)
    {
        int del=-1;
        //checking dag or not and has any node with indegree 0 or not
        for(int i=0;i<v;i++)
        {
            int fl=0;
            for(int j=0;j<v;j++)
            {
                if(adj[i][j]==1)
                {
                    fl=1;
                    break;
                }
            }
            if(fl==0){
                del=i;
                break;//break out of loop to continue
            }
        }
        
        //checking ends
        //if not dag
        if(del==-1)
        {
            printf("Sorting not possible\n");
            return;
        }

        //if dag and indegree zero removing the node(i.e., adding it order and removing the node)
        printf("%d\t",val[del]+1);
        //removing the connections of the node with indegree 0 from adj matrix to continue  
        for(int i=del;i<v-1;i++)
        {
            val[i]=val[i+1];
            for(int j=0;j<v;j++)
                adj[i][j]=adj[i][j+1];
        }

        for(int i=del;i<v-1;i++)
            for(int j=0;j<v;j++)
                adj[j][i]=adj[j+1][i];
        v--;
        printf("\n");
    }
}
void main()
{
    int v, i, j;
    printf("Enter number of vertices\n");
    scanf("%d", &v);
    printf("Enter adjacency matrix\n");
    int adj[100][100];
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            scanf("%d", &adj[i][j]);
    printf("Requiered order\n");
    taposort(adj, v);
    printf("\n");
} 