#include <stdio.h>

void println(int array[], int len)
{
    int i = 0;
    
    for(i=0; i<len; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");
}

void swap(int array[], int i, int j)
{
    int temp = array[i];
    
    array[i] = array[j];
    
    array[j] = temp;
}

void BubbleSort(int array[], int len) // O(n*n)
{
    int i = 0;
    int j = 0;
    int exchange = 1;
    
    for(i=0; (i<len) && exchange; i++)
    {
        exchange = 0;
        
        for(j=len-1; j>i; j--)
        {
            if( array[j] < array[j-1] )
            {
                swap(array, j, j-1);
                
                exchange = 1;
            }
        }
    }
}

int main()
{
    int array[] = {21, 25, 49, 25, 16, 8};
    int len = sizeof(array) / sizeof(*array); 
    
    println(array, len);
    
    BubbleSort(array, len);
    
    println(array, len);
    
    return 0;
}
