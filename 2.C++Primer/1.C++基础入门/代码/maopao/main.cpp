#include <iostream>
int main()
{
    int arry[] = {5,8,6,7,4,1,3,2};
    for (int i = 0; i < 7; i++)
    {
        /* code */
        for (int j = 0; j < 8-i-1; j++)
        {
            /* code */
            if (arry[j]>arry[j+1])
            {
                /* code */
                int temp=arry[j+1];
                arry[j+1]=arry[j];
                arry[j]=temp;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        /* code */
        std::cout<<arry[i]<<std::endl;
    }
    
    for (int i = 0; i < 7; i++)
    {
        /* code */
        for (int j = 0; j < 8-i-1; j++)
        {
            /* code */
            if (arry[j]<arry[j+1])
            {
                /* code */
                int temp=arry[j+1];
                arry[j+1]=arry[j];
                arry[j]=temp;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        /* code */
        std::cout<<arry[i]<<std::endl;
    } 
}