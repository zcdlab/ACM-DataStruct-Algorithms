#include <stdio.h>

int strlen(const char* s)
{
    if( s == NULL )
    {
        return -1;
    }
    else if( *s == '\0' )
    {
        return 0;
    }
    else
    {
        return strlen(s+1) + 1;
    }
}

int main()
{
    printf("strlen(\"12345\") = %d\n", strlen("12345"));
    printf("strlen(NULL) = %d\n", strlen(NULL));
    printf("strlen(\"\") = %d\n", strlen(""));
    
    return 0;
}
