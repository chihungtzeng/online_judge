#include <stdio.h>
#define LEN 101

long long matrix[LEN][LEN];
short n;

#if 0
void showMatrix(){
	short i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
#endif

int isSymmetric(){
	short i, j;
	short n_1 = n - 1;
	for(i=0; i<n; i++){
		for(j=i; j<n; j++){
			if(
				(matrix[i][j] < 0) ||
				(matrix[i][j] != matrix[n_1 - i][n_1 - j])
				){
				 return 0;
			}
		}
	}
	return 1;
}


int main(){
	short nTest, i, j, k = 1;
	FILE *fp = stdin;
	char dummy[2];
	fscanf(fp, "%hd", &nTest);
	while(nTest--){
		fscanf(fp, "%s %s %hd\n", dummy, dummy, &n);
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				fscanf(fp, "%lld", &matrix[i][j]);
			}
		}
		if(isSymmetric()){
			printf("Test #%hd: Symmetric.\n", k++);
		} else{
			printf("Test #%hd: Non-symmetric.\n", k++);
		}
	}
	return 0;
}