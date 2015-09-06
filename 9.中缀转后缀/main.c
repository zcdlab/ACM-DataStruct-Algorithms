#include <stdio.h>
#include "LinkStack.h"

int isNumber(char c)
{
    return ('0' <= c) && (c <= '9');
}

int isOperator(char c)
{
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isLeft(char c)
{
    return (c == '(');
}

int isRight(char c)
{
    return (c == ')');
}

int priority(char c)
{
    int ret = 0;
    
    if( (c == '+') || (c == '-') )
    {
        ret = 1;
    }
    
    if( (c == '*') || (c == '/') )
    {
        ret = 2;
    }
    
    return ret;
}

void output(char c)
{
    if( c != '\0' )
    {
        printf("%c", c);
    }
}

void transform(const char* exp)
{
    LinkStack* stack = LinkStack_Create();
    int i = 0;
    
    while( exp[i] != '\0' )
    {
        if( isNumber(exp[i]) )
        {
            output(exp[i]);
        }
        else if( isOperator(exp[i]) )
        {
            while( priority(exp[i]) <= priority((char)(int)LinkStack_Top(stack)) )
            {
                output((char)(int)LinkStack_Pop(stack));
            }
            
            LinkStack_Push(stack, (void*)(int)exp[i]);
        } 
        else if( isLeft(exp[i]) )
        {
            LinkStack_Push(stack, (void*)(int)exp[i]);
        } 
        else if( isRight(exp[i]) )
        {
            char c = '\0';
            
            while( !isLeft((char)(int)LinkStack_Top(stack)) )
            {
                output((char)(int)LinkStack_Pop(stack));
            }
            
            LinkStack_Pop(stack);
        }
        else
        {
            printf("Invalid expression!");
            break;
        }
        
        i++;
    }
    
    while( (LinkStack_Size(stack) > 0) && (exp[i] == '\0') )
    {
        output((char)(int)LinkStack_Pop(stack));
    }
    
    LinkStack_Destroy(stack);
}

int main()
{
    transform("9+(3-1)*5+8/2");
    
    printf("\n");
    
    return 0;
}
