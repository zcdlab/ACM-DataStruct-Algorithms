#include <stdio.h>
#include <malloc.h>

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

void Merge(int src[], int des[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    
    while( (i <= mid) && (j <= high) )
    {
        if( src[i] < src[j] )
        {
            des[k++] = src[i++];
        }
        else
        {
            des[k++] = src[j++];
        }
    }
    
    while( i <= mid )
    {
        des[k++] = src[i++];
    }
    
    while( j <= high )
    {
        des[k++] = src[j++];
    }
}

void MSort(int src[], int des[], int low, int high, int max)
{
    if( low == high )
    {
        des[low] = src[low];
    }
    else
    {
        int mid = (low + high) / 2;
        int* space = (int*)malloc(sizeof(int) * max);
        
        if( space != NULL )
        {
            MSort(src, space, low, mid, max);
            MSort(src, space, mid+1, high, max);
            Merge(space, des, low, mid, high);
        }
        
        free(space);
    }
}

void MergeSort(int array[], int len) // O(n*logn)
{
    MSort(array, array, 0, len-1, len);
}

int main()
{
    int array[] = {21, 25, 49, 25, 16, 8};
    int len = sizeof(array) / sizeof(*array); 
    
    println(array, len);
    
    MergeSort(array, len);
    
    println(array, len);
    
    return 0;
}
