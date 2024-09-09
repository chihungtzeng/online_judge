#include <stdio.h>
#include <stdlib.h>

int main(){
	srand(time(NULL));
	long long x, y, xy;
	short i;
	short total = 900;
	FILE *input, *output;
	
	input = fopen("in6.txt", "w");
	output = fopen("out6.txt", "w");
	fprintf(input, "%hd\n",total);
	i=0;

	while(i < 100){
		x = rand();

		if( (x > 1000000) ){
			xy = x*x;
			fprintf(input, "%lld\n",xy);
			fprintf(output, "%lld = %lld^2\n", xy, x);
			i++;
		}
	}
	while(i < total){
		x = rand();
		y = rand();
		if( (x > 1000000) && (y > 1000000)){
			xy = x*y;
			fprintf(input, "%lld\n",xy);
			fprintf(output, "%lld = %lld * %lld\n", xy, x, y);
			i++;
		}
	}
	fclose(input);
	fclose(output);
}
