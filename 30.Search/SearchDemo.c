#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SeqList.h"

#define SIZE 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void print_array(int a[], int len)
{
    int i = 0;
    
    for(i=0; i<len; i++)
    {
        printf("%d, ", a[i]);
    }
    
    printf("\n");
}

int static_search(int a[], int len, int key)
{
    int ret = -1;
    int i = 0;
    
    for(i=0; i<len; i++)
    {
        if( a[i] == key )
        {
            ret = i;
            break;
        }
    }
    
    return ret;
}

void print_list(SeqList* list)
{
    int i = 0;
    
    for(i=0; i<SeqList_Length(list); i++)
    {
        printf("%d, ", (int)SeqList_Get(list, i));
    }
    
    printf("\n");
}

int dynamic_search(SeqList* list, int key)
{
    int ret = -1;
    int i = 0;
    
    for(i=0; i<SeqList_Length(list); i++)
    {
        if( (int)SeqList_Get(list, i) == key )
        {
            ret = i;
            
            SeqList_Delete(list, i);
            
            break;
        }
    }
    
    return ret;
}

int main(int argc, char *argv[]) 
{
    SeqList* list = SeqList_Create(SIZE);
    int a[SIZE] = {0};
    int i = 0;
    int key = 0;
    int index = 0;
    
    srand((unsigned int)time(NULL));
    
    for(i=0; i<SIZE; i++)
    {
        a[i] = rand() % 100;
        SeqList_Insert(list, (SeqListNode*)(rand() % 100), i);
    }
    
    key = rand() % 100;
    
    printf("Static Search Demo\n");
    printf("Key: %d\n", key);
    printf("Array: \n");
    print_array(a, SIZE);
    
    index = static_search(a, SIZE, key);
    
    if( index >= 0 )
    {
        printf("Success: a[%d] = %d\n", index, a[index]);
    }
    else
    {
        printf("Failed!\n");
    }
    
    printf("Dynamic Search Demo\n");
    printf("Key: %d\n", key);
    printf("List: \n");
    print_list(list);
    
    index = dynamic_search(list, key);
    
    if( index >= 0 )
    {
        printf("Success: list[%d] = %d\n", index, key);
    }
    else
    {
        printf("Failed!\n");
    }
    
    print_list(list);
    
	return 0;
}
