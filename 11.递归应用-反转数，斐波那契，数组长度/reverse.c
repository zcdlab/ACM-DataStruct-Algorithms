#include <stdio.h>

void reverse(char* s)
{
    if( (s != NULL) && (*s != '\0') )
    {
        reverse(s + 1);
        
        printf("%c", *s);
    }
}

int main()
{
    reverse("12345");
    
    printf("\n");
    
    return 0;
}
