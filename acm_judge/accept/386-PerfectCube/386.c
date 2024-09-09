#include <stdio.h>
#include <stdlib.h>

#define CUBE(a) ((a)*(a)*(a))
#define MAX 201

int *cube;

struct Triple {
	unsigned char a, b, c, d;
};

int compareAns(const void *a, const void *b){
	struct Triple *x, *y;
	x = (struct Triple *)a;
	y = (struct Triple *)b;
	if(x->a < y->a) return -1;
	else if (x->a > y->a) return 1;
	else if (x->b < y->b) return -1;
	else if (x->b > y->b) return 1;
	else if (x->c < y->c) return -1;
	else if (x->c > y->c) return 1;
	else return 0;
}

int mybsearch(int target){
	int left, right, middle;
	left = 0;
	right = MAX - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(cube[middle] == target) return middle;
		else if (cube[middle] < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right) >> 1;
}

int main(){
	int a, b, c, d, i;
	int sum, index, nAns;
	struct Triple *ans;
			
	cube = (int *) malloc(sizeof(int)*MAX);
	ans = (struct Triple *) malloc(sizeof(struct Triple)*300);
	nAns = 0;
	
	for(a=0; a<MAX; a++){
		cube[a] = CUBE(a);
	} 
	
	for(b=2; b<MAX; b++){
		for(c=2; c<=b; c++){
			for(d=2; d<=c; d++){
				sum = cube[b] + cube[c] + cube[d];
				index = mybsearch(sum);
				if((index < MAX) && (cube[index] == sum)){
					ans[nAns].a = (unsigned char) index;
					ans[nAns].b = (unsigned char) d;
					ans[nAns].c = (unsigned char) c;
					ans[nAns].d = (unsigned char) b;
					nAns++;
					
				}
			}
		}
	}

	qsort(ans, nAns, sizeof(struct Triple), compareAns);
	for(i=0; i<nAns; i++){
		printf("Cube = %d, Triple = (%d,%d,%d)\n", ans[i].a, ans[i].b, ans[i].c, ans[i].d);
	}
	free(ans);
	free(cube);
	return 0;
}


