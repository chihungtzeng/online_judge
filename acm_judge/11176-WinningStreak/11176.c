#include <stdio.h>

/*
T[n,k] = 1 if k =0 or k=n
T[n,k] = 2T[n-1, k] + T[n-1,k-1] - 2T[n-2, k-1]
			+ T[n-k-1,k-1] - T[n-k-2, k]
*/

