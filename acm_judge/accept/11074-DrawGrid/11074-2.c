#include <stdio.h>
#include <stdlib.h>

size_t drawSymb(size_t oLen, char output[], int nSymb, char symb){
	size_t i;
	for(i = 0; i<nSymb; i++){
		output[oLen++] = symb;
	}  
	return oLen;
}

size_t drawGrid(int size, int thick, int n, size_t oLen, char output[]){
	int gLen, i, j, k;
	
	
	#if 0
		printf("size=%d, thick=%d, n=%d\n", size, thick, n);
	#endif
	
	/*gLen = (n + thick)*size + thick;*/
	gLen = n*(size + thick) + thick;
	/*top border*/
	for(i=0; i<thick; i++){
		oLen = drawSymb(oLen, output, gLen, '*');
		output[oLen++] = '\n';
	}
	/*grids*/
	for(i=0; i<n; i++){
		for(j=0; j<size; j++){
		/*leftmost border*/
			oLen = drawSymb(oLen, output, thick, '*');
			
			for(k=0; k<n; k++){
				/*other verticak borders and grid*/
				oLen = drawSymb(oLen, output, size, '.');
				oLen = drawSymb(oLen, output, thick, '*');
			}
			output[oLen++] = '\n';
		}
		
		for(j=0; j<thick; j++){
			oLen = drawSymb(oLen, output, gLen, '*');
			output[oLen++] = '\n';
		}
	}
	/*printf("%s", output);*/
	return oLen ;
}



int main(){
	short k = 1;
	char *output;
	int size, thick, n;
	size_t oLen = 0;
	output = (char *) malloc(16777216);
	while(3 == scanf("%d %d %d", &size, &thick, &n)){
		if((!size) && (!thick) && (!n)) break;
		else {
			
			oLen = sprintf(output, "Case %hd:\n", k++);
			oLen = drawGrid(size, thick, n, oLen, output);
			oLen += sprintf(output + oLen, "\n");
			write(1, output, oLen);
		} 
	}
	free(output);
	return 0;
}