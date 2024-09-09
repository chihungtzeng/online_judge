#include <stdio.h>
#define LEN 10
#define SWAP(a,b) (a) = (a) ^ (b) ; (b) = (a) ^ (b) ; (a) = (a) ^ (b)

char n, matrix[LEN][LEN];
char incMap[10], decMap[10];

void exchangeRow(char i, char j){
	char x;
	for(x=0; x<n; x++){
		SWAP(matrix[i][x], matrix[j][x]);
	}
}

void exchangeCol(char i, char j){
	char x;
	for(x=0; x<n; x++){
		SWAP(matrix[x][i], matrix[x][j]);
	}
}

void transpose(){
	char i,j;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			SWAP(matrix[i][j], matrix[j][i]);
		}
	}
}

void inc(){
	char i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matrix[i][j] = incMap[matrix[i][j]];
		}
	}
}

void dec(){
	char i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matrix[i][j] = decMap[matrix[i][j]];	
		}
	}
}

int main(){
	char nTest, nCommand, i, j, k= 1;
	char row, col;
	char line[LEN];
	FILE *fp = stdin;

	for(i=0; i<10; i++){
		incMap[i] = (i + 1) % 10;
		decMap[i] = (i + 9) % 10;
	}	
	#if 0
	for(i=0; i<10; i++){
		printf("%hhd", incMap[i]);
	}
	printf("\n");		
	for(i=0; i<10; i++){
		printf("%hhd", decMap[i]);
	}		
	printf("\n");
	#endif
	
	fscanf(fp, "%hhd", &nTest);
	while(nTest--){
		fscanf(fp, "%hhd", &n);
		for(row=0; row<n; row++){
			fscanf(fp, "%s", line);
			for(col=0; col<n; col++){
				matrix[row][col] = line[col] - '0';
			}
		}
		fscanf(fp, "%hhd", &nCommand);
		while(nCommand--){
			fscanf(fp, "%s", line);
			if(strcmp(line, "row") == 0){
				fscanf(fp, "%hhd %hhd", &i, &j);
				exchangeRow(i - 1, j - 1);
			} else if (strcmp(line, "col") == 0){
				fscanf(fp, "%hhd %hhd", &i, &j);
				exchangeCol(i - 1, j - 1);
			} else if (strcmp(line, "inc") == 0){
				inc();
			} else if (strcmp(line, "dec") == 0){
				dec();
			} else if (strcmp(line, "transpose") == 0){
				transpose();
			}
		}
		/*output*/
		printf("Case #%hhd\n",k++);
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				printf("%c", matrix[i][j] + '0');
			}
			printf("\n");
		}
		printf("\n");
	}	
	
	return 0;
}