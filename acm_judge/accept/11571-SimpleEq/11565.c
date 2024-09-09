
#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int main( int argc, char* argv[] ) {



    int A, B, C;

    int x, y, z;

    int count, found;



    scanf("%d", &count);

    while ( count-- > 0 ) {



        scanf("%d %d %d", &A, &B, &C);



        if ( A < 1 || B < 1 || C < 1 || A > 10000 || B > 10000 || C > 10000 ) {

            printf( "No solution.\n" );

            continue;

        }



        found = 0;

        for ( x = -100; !found && x <= 100; ++x ) {



            if ( 2*x*x*x - 2*A*x*x + (A*A-C)*x - 2*B == 0) {



                for ( y = -100; !found && y <= 100; ++y ) {



                    if ( x*y*y + x*x*y - A*x*y + B == 0 ) {



                        z = A - x - y;



                        if (   x != y && y != z && x != z

                                && x*x + y*y + z*z == C

                           ) {

                            printf( "%d %d %d\n", x, y, z );

                            found = 1;

                        }



                    }



                }



            }



        }



        if (!found) printf( "No solution.\n" );

    }



    return 0;

}

