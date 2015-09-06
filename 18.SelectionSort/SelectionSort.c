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

void SelectionSort(int array[], int len) // O(n*n)
{
    int i = 0;
    int j = 0;
    int k = -1;
    
    for(i=0; i<len; i++)
    {
        k = i;
        
        for(j=i; j<len; j++)
        {
            if( array[j] < array[k] )
            {
                k = j;
            }
        }
        
        swap(array, i, k);
    }
}

int main()
{
    int array[] = {21, 25, 49, 25, 16, 8};
    int len = sizeof(array) / sizeof(*array); 
    
    println(array, len);
    
    SelectionSort(array, len);
    
    println(array, len);
    
    return 0;
}
