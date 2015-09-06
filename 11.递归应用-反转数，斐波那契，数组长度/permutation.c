#include <stdio.h>

void permutation(char s[], int b, int e)
{
    if( (0 <= b) && (b <= e) )
    {
        if( b == e )
        {
            printf("%s\n", s);
        }
        else
        {
            int i = 0;
            
            for(i=b; i<=e; i++)
            {
                char c = s[b];
                s[b] = s[i];
                s[i] = c;
                
                permutation(s, b+1, e);
                
                c = s[b];
                s[b] = s[i];
                s[i] = c;
            }
        }
    }
}

int main()
{
    char s[] = "abcd";
    
    permutation(s, 0, 3);
    
    return 0;
}
