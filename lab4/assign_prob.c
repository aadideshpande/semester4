    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>
    #include<time.h>
    int min[1000], min_value = INT_MAX;
    int opcount = 0;
    void printCombinations(int size, int arr[size][size], int buf[size], int buf_1[size], int ix)
    {
        opcount++;
        int i, j;
        if (ix == size)
        {
            int sum = 0, flag = 1;
            for (i = 0; i < size; i++)
                sum += buf[i];
            for (i = 0; i < size - 1; i++)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (buf_1[i] == buf_1[j])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (sum < min_value && flag)
            {
                for (i = 0; i < size; i++)
                    min[i] = buf[i];
                min_value = sum;
            }
        }
        else
        {
            for (i = 0; i < size; i++)
            {
                buf[ix] = arr[i][ix];
                buf_1[ix] = i;
                printCombinations(size, arr, buf, buf_1, ix + 1);
            }
        }
    }
    void main()
    {
        int i, j, size;
        double start_time,end_time;
        double total_time;
        FILE *output;
        output=fopen("q1.csv","a");
        //fprintf(output, "inputsize ,time\n" );
        printf("Enter the Size of the Square Matrix:\n");
        scanf("%d", &size);
        int arr[size][size];
        printf("Enter Person vs Job Cost Matrix :\n");
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
                scanf("%d", &arr[i][j]);
        }
        int buff[size];
        int buff_1[size];
        start_time=clock();
        printCombinations(size, arr, buff, buff_1, 0);
        end_time=clock();
        total_time=(double)(end_time-start_time)/CLOCKS_PER_SEC;
        fprintf(output, "%d,%f \n",size,total_time);
        fclose(output);
        //printf("The Minimum Cost Combination is : ");
       // for (j = 0; j < size; j++)
         //   printf("%d ", min[j]);
        printf("\nThe Minimum Cost is : %d\n", min_value);
        printf("opcount is %d \n", opcount);
    return;
    }