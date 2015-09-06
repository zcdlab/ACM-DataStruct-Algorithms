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

void ShellSort(int array[], int len) // O(n*n)
{
    int i = 0;
    int j = 0;
    int k = -1;
    int temp = -1;
    int gap = len;
    
    do
    {
        gap = gap / 3 + 1; 
    
        for(i=gap; i<len; i+=gap)
        {
            k = i;
            temp = array[k];
            
            for(j=i-gap; (j>=0) && (array[j]>temp); j-=gap)
            {
                array[j+gap] = array[j];
                k = j;
            }
        
            array[k] = temp;
        }
        
    }while( gap > 1 );
    
}

int main()
{
    int array[] = {21, 25, 49, 25, 16, 8};
    int len = sizeof(array) / sizeof(*array); 
    
    println(array, len);
    
    ShellSort(array, len);
    
    println(array, len);
    
    return 0;
}
