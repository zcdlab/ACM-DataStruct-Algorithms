#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
    LinkStack* stack = LinkStack_Create();
    int a[10];
    int i = 0;
    
    for(i=0; i<10; i++)
    {
        a[i] = i;
        
        LinkStack_Push(stack, a + i);
    }
    
    printf("Top: %d\n", *(int*)LinkStack_Top(stack));
    printf("Length: %d\n", LinkStack_Size(stack));
    
    while( LinkStack_Size(stack) > 0 )
    {
        printf("Pop: %d\n", *(int*)LinkStack_Pop(stack));
    }
    
    LinkStack_Destroy(stack);
    
	return 0;
}
