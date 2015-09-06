#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
    SeqQueue* queue = SeqQueue_Create(20);
    int a[10] = {0};
    int i = 0;
    
    for(i=0; i<10; i++)
    {
        a[i] = i + 1;
        
        SeqQueue_Append(queue, a + i);
    }
    
    printf("Header: %d\n", *(int*)SeqQueue_Header(queue));
    printf("Length: %d\n", SeqQueue_Length(queue));
    printf("Capacity: %d\n", SeqQueue_Capacity(queue));
    
    while( SeqQueue_Length(queue) > 0 )
    {
        printf("Retrieve: %d\n", *(int*)SeqQueue_Retrieve(queue));
    }
    
    SeqQueue_Destroy(queue);
    
	return 0;
}
