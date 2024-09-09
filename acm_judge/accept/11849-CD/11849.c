#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m, i, j;
	int count;
	
	long long *jack, *jill;
	long long x;
	while(2 == scanf("%d %d", &n, &m)){
		if( (0 == n) && (0 == m)) return 0;
		
		jack = (long long *) malloc(sizeof(long long)*n);
		count = 0;
				
		for(i=0; i<n; i++){
			scanf("%lld", jack+i);
		}
		i=0;
		for(j=0; j<m; j++){
			scanf("%lld", &x);
			while((i<n) && (jack[i] < x)){
				i++;
			}
			if((i<n) && (jack[i] == x)){
				i++;
				count++;
			}
		}


		free(jack);

		printf("%d\n", count);
	}
	return 0;
}