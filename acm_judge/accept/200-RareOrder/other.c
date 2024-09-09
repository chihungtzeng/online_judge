#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

void compare_str( const char *a, const char *b, int adj[MAX][MAX], int degree[MAX], int out_degree[MAX])
{
    while( *a && *b && *a == *b )
    {
        a++;
        b++;
    }

    if( *a && *b )
    {
        
        int alpha_a = *a - 'A';
        int alpha_b = *b - 'A';
        if( adj[alpha_b][alpha_a] == 0 )
        {
            adj[alpha_b][alpha_a] = 1;
            degree[alpha_a]++;
            degree[alpha_b]++;
            out_degree[alpha_b]++;
        }
    }
}

void topo_print( int adj[MAX][MAX], int degree[MAX], int out_degree[MAX] )
{
    int alphabets[MAX];
    int alphabets_max = 0;

    for( int i = 0; i < MAX; ++i )
    {
        if( degree[i] )
        {
            alphabets[alphabets_max++] = i;
        }
    }

    
    for( int i = 0; i < alphabets_max; ++i )
    {
        
        int alpha = -1;
        for( int j = 0; j < alphabets_max; ++j )
        {
            int current_alpha = alphabets[j];
            if( out_degree[current_alpha] == 0 )
            {
                alpha = current_alpha;
                out_degree[current_alpha] = -1;
                putchar(alpha + 'A');
                
                break;
            }
        }

        
        for( int j = 0; j < alphabets_max; ++j )
        {
            int current_alpha = alphabets[j];
            if( adj[current_alpha][alpha] > 0 )
            {
                out_degree[current_alpha]--;
                adj[current_alpha][alpha] = 0;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int adj[MAX][MAX];    
    int out_degree[MAX];
    int degree[MAX];
    int n = 0;

    memset( adj, 0, sizeof(adj) );
    memset( out_degree, 0, sizeof(out_degree) );
    memset( degree, 0, sizeof(degree) );

    bool quit = false;

    char *prev_str = new char[255];
    char *current_str = new char[255];

    scanf("%s", prev_str);
    n++;

    while(!quit)
    {
        scanf("%s", current_str);
        
        if( strcmp( current_str, "#" ) == 0 )
            quit = true;
        else
        {
            n++;

            compare_str( prev_str, current_str, adj, degree, out_degree );

            
            char *temp = prev_str;
            prev_str = current_str;
            current_str = temp;
        }
    }

    if( n == 1 )
        putchar(prev_str[0]);
    else
        topo_print(adj, degree, out_degree);

    putchar('\n');
    

    delete prev_str;
    delete current_str;

    return 0;
}
