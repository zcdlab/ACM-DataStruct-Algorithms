#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

int binary_search(int a[], int low, int high, int key) // O(logn)
{
    int ret = -1;
    
    if( low <= high )
    {
        int mid = (low + high) / 2;
        
        if( a[mid] == key )
        {
            ret = mid;
        }
        else if( key < a[mid] )
        {
            ret = binary_search(a, low, mid-1, key);
        }
        else if( key > a[mid] )
        {
            ret = binary_search(a, mid+1, high, key);
        }
    }
    
    return ret;
}

int binary_search_ex(int a[], int low, int high, int key) // O(logn)
{
    int ret = -1;
    
    while( low <= high )
    {
        int mid = (low + high) / 2;
        
        if( a[mid] == key )
        {
            ret = mid;
            break;
        }
        else if( key < a[mid] )
        {
            high = mid - 1;
        }
        else if( key > a[mid] )
        {
            low = mid + 1;
        }
    }
    
    return ret;
}

int interpolation_search(int a[], int low, int high, int key)
{
    int ret = -1;
    
    while( (low <= high) && (a[low] <= key) && (key <= a[high]) )
    {
        float fx = 1.0f * (key - a[low]) / (a[high] - a[low]);
        int mid = low + fx * (high - low);
        
        if( a[mid] == key )
        {
            ret = mid;
            break;
        }
        else if( key < a[mid] )
        {
            high = mid - 1;
        }
        else if( key > a[mid] )
        {
            low = mid + 1;
        }
    }
    
    return ret;
}

int main(int argc, char *argv[]) 
{
    int a[SIZE] = {0};
    int i = 0;
    int key = 0;
    int index = 0;
    
    srand((unsigned int)time(NULL));
    
    for(i=1; i<=SIZE; i++)
    {
        a[i] = rand() % 100;
    }
    
    key = 50;
    
    printf("Binary Search Demo\n");
    printf("Key: %d\n", key);
    printf("Array: \n");
    
    SelectionSort(a, SIZE);
    
    println(a, SIZE);
    
    index = interpolation_search(a, 0, SIZE-1, key);
    
    if( index > 0 )
    {
        printf("Success: a[%d] = %d\n", index, a[index]);
    }
    else
    {
        printf("Failed!\n");
    }
    
	return 0;
}
