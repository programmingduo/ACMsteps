
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int p;
    int v;
    int dec;
}N[1005];

int cmp( const void *a, const void *b )
{
    struct Node *x= ( struct Node * )a, *y= ( struct Node * )b;
    return y-> dec- x-> dec;
}

int main(  )
{
    int T;
    scanf( "%d", &T );
    while( T-- )
    {
        int ta, M, flag= 0;
        scanf( "%d %d", &ta, &M );
        for( int i= 0; i< M; ++i )
        {
            scanf( "%d %d", &N[i]. p, &N[i]. v );
            N[i]. dec= N[i]. v- N[i]. p;
        }
        qsort( N, M, sizeof( N[0] ), cmp );
        for( int i= 0; i< M; ++i )
        {
            if( ta>= N[i]. v )
            {
                ta-= ( N[i]. p);
            }
            else
            {
                flag= 1;
                break;
            }
        }
        printf( flag? "No\n": "Yes\n" );
    }
    return 0;
}
