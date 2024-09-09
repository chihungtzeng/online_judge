#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <setjmp.h>
#define DEBUG 0
#define INC 0
#define DEC 1

long long eValue[2];
jmp_buf buf;
int k;
int (*compr[2])();

void *root[2], *match;

struct Bill{
	long long amount;
	long long occr;
};

struct Bill *newBill(long long c){
	struct Bill *b;
	b = (struct Bill *) malloc(sizeof(struct Bill));
	b->occr = 1;
	b->amount = c;
	return b;
}


int compareBillInc(const void *a, const void *b){
	struct Bill *x, *y;
	x = (struct Bill *)a;
	y = (struct Bill *)b;
	if(x->amount > y->amount) return 1;
	else if (x->amount < y->amount) return -1;
	else return 0;
	
}

int compareBillDec(const void *a, const void *b){
	/*
	struct Bill *x, *y;
	x = (struct Bill *)a;
	y = (struct Bill *)b;
	return y->amount - x->amount;
	*/
	return -compareBillInc(a, b);
}

void twalkActionForMin(const void *rootp, const VISIT which, int depth){
	struct Bill *b;
	
	if( (depth == 0) && ((which == preorder) || (which == leaf))){
		b = *(struct Bill **) rootp;
		eValue[k] = b->amount;
	}
	
	if( (depth > 0) && ((which == leaf) || (which == preorder))){
		b = *(struct Bill **) rootp;
		if(k == INC){
			eValue[k] = (eValue[k] > b->amount)?
				b->amount : eValue[k];   
		}
		else{
			eValue[k] = (eValue[k] < b->amount)?
				b->amount : eValue[k]; 
		}
	}
	
	if((which == leaf)){
		longjmp(buf, 1);
	}
	
}

void twalkActionForPrint(const void *rootp, const VISIT which, int depth){
	struct Bill *b;
	char *wtype;
	if(which == preorder){
		wtype = strdup("preorder");
	}
	else if (which == postorder){
		wtype = strdup("postorder");
	}
	else if (which == endorder){
		wtype = strdup("endorder");
	}
	else if (which == leaf){
		wtype = strdup("leaf");
	}
	else{
		wtype = strdup("unknown");
	}
	b = *(struct Bill **) rootp;
	printf("(%lld(%lld) %s depth=%d) ", b->amount, b->occr, wtype, depth);
	free(wtype);
}


void tfindMin(void *root){
	if(setjmp(buf)){
	}
	else{
		twalk(root, twalkActionForMin);
	}
}

int main(){
	struct Bill *bill, *query;
	int nDay, i, j, nBill, ell;
	long long sum, amount;
	
	
	FILE *fp;
	
	fp = (DEBUG)? fopen("in4.txt", "r") : stdin;
	compr[INC] = compareBillInc;
	compr[DEC] = compareBillDec;
	
	while(1 == fscanf(fp, "%d", &nDay)){
		if(0 == nDay) return 0;
		
		if(DEBUG){
			puts("------------Begin New Case-----------");
		}
		root[0] = NULL;
		root[1] = NULL;
		sum = 0;
		for(i=0; i<nDay; i++){
			fscanf(fp, "%d", &nBill);
			for(j=0; j<nBill; j++){
				fscanf(fp, "%lld", &amount);
				
				for(k=0; k<2; k++){
					bill = newBill(amount);					
					match = tsearch(bill, &root[k], compr[k]);
					if(*(struct Bill **)match != bill){
						free(bill);
						bill = *(struct Bill **)match;
						bill->occr += 1;
					}
				}
			}
			
			for(k=0; k<2; k++){
				
				if(DEBUG){
					printf("root %d:\n", k);
					twalk(root[k], twalkActionForPrint);
					printf("\n\n");
				}
				
				tfindMin(root[k]);		
			}
			
			sum += eValue[1] - eValue[0];
			
			for(k=0; k<2; k++){				
				/*compr = (k == 0)? compareBillInc : compareBillDec;*/
				for(ell = 0; ell < 2; ell++){
					query = newBill(eValue[ell]);
					match = tfind(query, &root[k], compr[k]);
					if(!match){
						if(DEBUG){
							printf("ERROR: No match for query value %lld at tree %d\n", query->amount, k);
						}
						continue;
					}
					bill = *(struct Bill **)match;
					
					query->occr = bill->occr - 1;
					tdelete(bill, &root[k], compr[k]);
					free(bill);
					
					if(query->occr > 0){
						tsearch(query, &root[k], compr[k]);												
					}
					else{
						free(query);
					}
				}
				if(DEBUG){
					printf("root %d after deletion:\n", k);
					twalk(root[k], twalkActionForPrint);
					printf("\n\n");
				}
			}

			
			if(DEBUG){
				printf("min=%lld max=%lld\n", eValue[0], eValue[1]);
			}
		}
		
		printf("%lld\n", sum);
		tdestroy(root[0], free);
		tdestroy(root[1], free);
		
	}
	
	return 0;
}