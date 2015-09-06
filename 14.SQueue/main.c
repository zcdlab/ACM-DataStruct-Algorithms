#include <stdio.h>
#include <stdlib.h>
#include "SQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
    SQueue* queue = SQueue_Create();
    int a[10] = {0};
    int i = 0;
    
    for(i=0; i<10; i++)
    {
        a[i] = i + 1;
        
        SQueue_Append(queue, a + i);
    }
    
    printf("Header: %d\n", *(int*)SQueue_Header(queue));
    printf("Length: %d\n", SQueue_Length(queue));
    
    for(i=0; i<5; i++)
    {
        printf("Retrieve: %d\n", *(int*)SQueue_Retrieve(queue));
    }
    
    printf("Header: %d\n", *(int*)SQueue_Header(queue));
    printf("Length: %d\n", SQueue_Length(queue));
    
    for(i=0; i<10; i++)
    {
        a[i] = i + 1;
        
        SQueue_Append(queue, a + i);
    }
    
    while( SQueue_Length(queue) > 0 )
    {
        printf("Retrieve: %d\n", *(int*)SQueue_Retrieve(queue));
    }
    
    SQueue_Destroy(queue);
    
	return 0;
}
