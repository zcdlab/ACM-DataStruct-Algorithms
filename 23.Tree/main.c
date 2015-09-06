#include <stdio.h>
#include "GTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printf_data(GTreeData* data)
{
    printf("%c", (int)data);
}

int main(int argc, char *argv[])
{
    GTree* tree = GTree_Create();
    int i = 0;
    
    GTree_Insert(tree, (GTreeData*)'A', -1);
    GTree_Insert(tree, (GTreeData*)'B', 0);
    GTree_Insert(tree, (GTreeData*)'C', 0);
    GTree_Insert(tree, (GTreeData*)'D', 0);
    GTree_Insert(tree, (GTreeData*)'E', 1);
    GTree_Insert(tree, (GTreeData*)'F', 1);
    GTree_Insert(tree, (GTreeData*)'H', 3);
    GTree_Insert(tree, (GTreeData*)'I', 3);
    GTree_Insert(tree, (GTreeData*)'J', 3);
    
    printf("Tree Height: %d\n", GTree_Height(tree));
    printf("Tree Degree: %d\n", GTree_Degree(tree));
    printf("Full Tree:\n");
    
    GTree_Display(tree, printf_data, 2, ' ');
    
    printf("Get Tree Data:\n");
    
    for(i=0; i<GTree_Count(tree); i++)
    {
        printf_data(GTree_Get(tree, i));
        printf("\n");
    }
    
    printf("Get Root Data:\n");
    
    printf_data(GTree_Root(tree));
    
    printf("\n");
    
    GTree_Delete(tree, 3);
     
    printf("After Deleting D:\n");
    
    GTree_Display(tree, printf_data, 2, '-');
    
    GTree_Clear(tree);
    
    printf("After Clearing Tree:\n");
    
    GTree_Display(tree, printf_data, 2, '.');
        
    GTree_Destroy(tree);
    
	return 0;
}
