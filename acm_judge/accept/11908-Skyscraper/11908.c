#include <stdio.h>
#define MAX 30001
#define VERBOSE 0
#define DEBUG 0

struct Ad{
	int start, end;
	int money;
};

struct Ad ad[MAX];
int nAd;
int nAdMinusOne;

int compareAd(const void *a, const void *b){
	struct Ad *x, *y;
	x = (struct Ad *)a;
	y = (struct Ad *)b;
	
	if(x->end != y->end) return x->end - y->end;
	else return x->start - y->start;
	
}

int mybsearch(int target){
	int left, right, middle;
	left = 0;
	right = nAdMinusOne;
	while(left <= right){
		middle = (left + right) >> 1;
		if(ad[middle].end == target) return middle;
		else if(ad[middle].end < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right)/2;
}

int findAns(){
	int pre[nAd];
	int benefit[nAd + 1];
	int i, j;
	int sum;
	for(i=0; i<nAd; i++){
		pre[i] = mybsearch(ad[i].start);
		while( (pre[i] < nAd) && (ad[pre[i]].end <= ad[i].start)){
			pre[i]++;
		} 
	}
	if(VERBOSE){
		printf("pre function:\n");
		for(i=0; i<nAd; i++){
			printf("%d ", pre[i]);
		}
		printf("\n");
	}

	benefit[0] = 0;
	j=0;
	for(i=1; i <= nAd; i++){
		
		sum = ad[j].money + benefit[pre[j]];
		if(sum > benefit[j]){
			benefit[i] = sum;
		}
		else{
			benefit[i] = benefit[j];
		}
		j = i;
	}
	
	return benefit[nAd];
}

int main(){
	char nTest, k=1;
	int i;
	int ans;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	fscanf(fp, "%hhd", &nTest);
	while(k <= nTest){
		fscanf(fp, "%d", &nAd);
		for(i=0; i<nAd; i++){
			fscanf(fp, "%d %d %d", &ad[i].start, &ad[i].end, &ad[i].money);
			ad[i].end += ad[i].start;
		}
		qsort(ad, nAd, sizeof(struct Ad), compareAd);
		nAdMinusOne = nAd - 1;
		if(VERBOSE){
			for(i=0; i<nAd; i++){
				printf("ad %hhd: start:%d end:%d money:%d\n", i, ad[i].start, ad[i].end, ad[i].money);
			}
		}
		ans = findAns();
		printf("Case %hhd: %d\n",k++, ans);
	}
		
	
	return 0;
}