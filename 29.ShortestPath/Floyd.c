#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define VNUM 5
#define MV 65536

int P[VNUM][VNUM];
int A[VNUM][VNUM];
int Matrix[VNUM][VNUM] =
{
    {0, 10, MV, 30, 100},
    {MV, 0, 50, MV, MV},
    {MV, MV, 0, MV, 10},
    {MV, MV, 20, 0, 60},
    {MV, MV, MV, MV, 0},
};

void Floyd() // O(n*n*n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    for(i=0; i<VNUM; i++)
    {
        for(j=0; j<VNUM; j++)
        {
            A[i][j] = Matrix[i][j];
            P[i][j] = j;
        }
    }
    
    for(i=0; i<VNUM; i++)
    {
        for(j=0; j<VNUM; j++)
        {
            for(k=0; k<VNUM; k++)
            {
                if( (A[j][i] + A[i][k]) < A[j][k] )
                {
                    A[j][k] = A[j][i] + A[i][k];
                    P[j][k] = P[j][i];
                }
            }
        }
    }
    
    for(i=0; i<VNUM; i++)
    {
        for(j=0; j<VNUM; j++)
        {
            int p = -1;
            
            printf("%d -> %d: %d\n", i, j, A[i][j]);
            
            printf("%d", i);
            
            p = i;
            
            do
            {
                p = P[p][j];
                
                printf(" -> %d", p);
            } while( p != j);
            
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) 
{
    Floyd();
    
	return 0;
}

