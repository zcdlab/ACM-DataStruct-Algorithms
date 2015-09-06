#include <stdio.h>

typedef struct _tag_DataElem
{
    char desc[20];
    int key1;
    int key2;
} DataElem;

int compare1(DataElem* ld, DataElem* rd)
{
    int ret = 0;
    
    if( ld->key1 > rd->key1 )
    {
        ret = 1;
    }
    else if( ld->key1 == rd->key1 )
    {
        if( ld->key2 > rd->key2 )
        {
            ret = 1;
        }
        
        if( ld->key2 < rd->key2 )
        {
            ret = -1;
        }
    }
    else
    {
        ret = -1;
    }
    
    return ret;
}

int compare2(DataElem* ld, DataElem* rd)
{
    return (ld->key1*100 + ld->key2) - (rd->key1*100 + rd->key2);
}

int main()
{
    DataElem d1 = {"d1", 91, 80};
    DataElem d2 = {"d2", 91, 88};
    
    printf("Compare1 %s and %s: %d\n", d1.desc, d2.desc, compare1(&d1, &d2));
    printf("Compare2 %s and %s: %d\n", d1.desc, d2.desc, compare2(&d1, &d2));
    
    return 0;
}

