#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define VNUM 5
#define MV 65536

int P[VNUM];
int Dist[VNUM];
int Mark[VNUM];
int Matrix[VNUM][VNUM] =
{
    {0, 10, MV, 30, 100},
    {MV, 0, 50, MV, MV},
    {MV, MV, 0, MV, 10},
    {MV, MV, 20, 0, 60},
    {MV, MV, MV, MV, 0},
};

void Dijkstra(int sv) // O(n*n)
{
    int i = 0;
    int j = 0;
    
    if( (0 <= sv) && (sv < VNUM) )
    {
        for(i=0; i<VNUM; i++)
        {
            Dist[i] = Matrix[sv][i];
            P[i] = sv;
            Mark[i] = 0;
        }
        
        Mark[sv] = 1;
        
        for(i=0; i<VNUM; i++)
        {
            int min = MV;
            int index = -1;
            
            for(j=0; j<VNUM; j++)
            {
                if( !Mark[j] && (Dist[j] < min) )
                {
                    min = Dist[j];
                    index = j;
                }
            }
            
            if( index > -1 )
            {
                Mark[index] = 1;
            }
            
            for(j=0; j<VNUM; j++)
            {
                if( !Mark[j] && (min + Matrix[index][j] < Dist[j]) )
                {
                    Dist[j] = min + Matrix[index][j];
                    P[j] = index;
                }
            }
        }
        
        for(i=0; i<VNUM; i++)
        {
            int p = i;
            
            printf("%d -> %d: %d\n", sv, p, Dist[p]);
            
            do
            {
                printf("%d <- ", p);
                p = P[p];
            } while( p != sv );
            
            printf("%d\n", p);
        }
    }
}

int main(int argc, char *argv[]) 
{
    Dijkstra(0);

	return 0;
}

