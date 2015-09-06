#include <stdio.h>

int fibonacci(int n)
{
    if( n > 1 )
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
    else if( n == 1 )
    {
        return 1;
    }
    else if( n == 0 )
    {
        return 0;
    }
}

int main()
{
    int i = 0;
    
    for(i=1; i<=10; i++)
    {
        printf("fibonacci(%d) = %d\n", i, fibonacci(i));
    }
    
    return 0;
}
