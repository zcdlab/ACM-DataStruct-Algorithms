#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isLeft(char c)
{
    int ret = 0;
    
    switch(c)
    {
        case '<':
        case '(':
        case '[':
        case '{':
        case '\'':
        case '\"':
            ret = 1;
        	break;
        default:
            ret = 0;
            break;
    }
    
    return ret;
}

int isRight(char c)
{
    int ret = 0;
    
    switch(c)
    {
        case '>':
        case ')':
        case ']':
        case '}':
        case '\'':
        case '\"':
            ret = 1;
        	break;
        default:
            ret = 0;
            break;
    }
    
    return ret;
}

int match(char left, char right)
{
    int ret = 0;
    
    switch(left)
    {
        case '<':
            ret = (right == '>');
            break;
        case '(':
            ret = (right == ')');
            break;
        case '[':
            ret = (right == ']');
            break;
        case '{':
            ret = (right == '}');
            break;
        case '\'':
            ret = (right == '\'');
            break;
        case '\"':
            ret = (right == '\"');
            break;
        default:
            ret = 0;
            break;
    }
    
    return ret;
}

int scanner(const char* code)
{
    LinkStack* stack = LinkStack_Create();
    int ret = 0;
    int i = 0;
    
    while( code[i] != '\0' )
    {
        if( isLeft(code[i]) )
        {
            LinkStack_Push(stack, (void*)(code + i));
        }
        
        if( isRight(code[i]) )
        {
            char* c = (char*)LinkStack_Pop(stack);
            
            if( (c == NULL) || !match(*c, code[i]) )
            {
                printf("%c does not match!\n", code[i]);
                ret = 0;
                break;
            }
        }
        
        i++;
    }
    
    if( (LinkStack_Size(stack) == 0) && (code[i] == '\0') )
    {
        printf("Succeed!\n");
        ret = 1;
    }
    else
    {
        printf("Invalid code!\n");
        ret = 0;
    }
    
    LinkStack_Destroy(stack);
    
    return ret;
}

int main(int argc, char *argv[])
{
    const char* code = "#include <stdio.h> int main() { int a[5][5]; int (*p)[4]; p = a[0]; printf(\"%d\\n\", &p[3][3] - &a[3][3]); return 0; }";
    
    scanner(code);
    
	return 0;
}
