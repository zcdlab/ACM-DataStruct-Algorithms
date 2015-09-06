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

void InertionSort(int array[], int len) // O(n*n)
{
    int i = 0;
    int j = 0;
    int k = -1;
    int temp = -1;
    
    for(i=1; i<len; i++)
    {
        k = i;
        temp = array[k];
        
        for(j=i-1; (j>=0) && (array[j]>temp); j--)
        {
            array[j+1] = array[j];
            k = j;
        }
        
        array[k] = temp;
    }
}

int main()
{
    int array[] = {21, 25, 49, 25, 16, 8};
    int len = sizeof(array) / sizeof(*array); 
    
    println(array, len);
    
    InertionSort(array, len);
    
    println(array, len);
    
    return 0;
}
