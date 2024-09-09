#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#define N 1000000
using namespace std;

int a [N + 10];

void precalculate ()
{
    a [0] = 1;

    for ( int i = 1; i <= N; i++ ) {
        a [i] = a [(int)floor(i - sqrt (i))] + a [(int)floor (log (i))] + a [(int)floor (i * sin (i) * sin (i))];
        a [i] %= N;
    }
}

int main ()
{
    precalculate ();

    int input;

    while ( scanf ("%d", &input) && input != -1 ) {
        printf ("%d\n", a [input]);
    }

    return 0;
}
