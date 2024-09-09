#include <stdio.h>
#include <stdlib.h>
#include <search.h>

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}


int main(){
	int a0, a0square;
	int *value, *match;
	int count;
	void *root;
	char done;

	while(1 == scanf("%d", &a0)){
		if(0 == a0){
			break;
		}
		count = 1;
		root = NULL;		
		done = 0;
		value = (int *) malloc(sizeof(int));
		*value = a0;
		tsearch(value, &root, compareInt);
		while(!done){
			a0square = a0*a0;
			
			
			a0square = a0square / 100;
			a0square = a0square % 10000;
			if(a0square == 0){
				/*what follows is always 0*/
				count++;
				done = 1;
				continue;
			}
			value = (int *) malloc(sizeof(int));
			*value = a0square;
			match = *(int **) tsearch(value, &root, compareInt);
			if(match == NULL){
				printf("insufficient memory\n");
				exit(0);
			}
			else if (match != value){
				/*repeat element has found!*/
				done = 1;
				tdestroy(root, free);
			}
			else{
				count++;
				a0 = a0square;
			}
		}
		printf("%d\n",count);
	}

	return 0;
}
