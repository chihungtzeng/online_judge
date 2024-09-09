#include <stdio.h>

int s, t, n;

void drawing_line ()
{
    int length = (s * n) + ((n + 1) * t);

        for ( int i = 0; i < t; i++ ) {
                for ( int j = 0; j < length; j++ )
                            printf ("*");
                                    printf ("\n");
                                        }
                                        }

                                        void grid ()
                                        {
                                            for ( int i = 0; i < s; i++ ) {
                                                    for ( int j = 0; j < n; j++ ) {
                                                                for ( int k = 0; k < t; k++ )
                                                                                printf ("*");
                                                                                            for ( int k = 0; k < s; k++ )
                                                                                                            printf (".");
                                                                                                                    }

                                                                                                                            for ( int k = 0; k < t; k++ )
                                                                                                                                        printf ("*");
                                                                                                                                                printf ("\n");
                                                                                                                                                    }

                                                                                                                                                    }

                                                                                                                                                    int main ()
                                                                                                                                                    {
                                                                                                                                                        int cases = 0;

                                                                                                                                                            while ( scanf ("%d %d %d", &s, &t, &n) ) {
                                                                                                                                                                    if ( s == 0 && t == 0 && n == 0 )
                                                                                                                                                                                return 0;

                                                                                                                                                                                        printf ("Case %d:\n", ++cases);

                                                                                                                                                                                                for ( int i = 0; i < n; i++ ) {
                                                                                                                                                                                                            drawing_line ();
                                                                                                                                                                                                                        grid ();
                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                        drawing_line ();

                                                                                                                                                                                                                                                printf ("\n");
                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                        return 0;
                                                                                                                                                                                                                                                        }

