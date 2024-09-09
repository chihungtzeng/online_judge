/*AC*/
#include <stdio.h>
#include <math.h>

#define UB 1000000
/*#define UB 100*/

int N[1000000];
int nNum;

int findSeq(){
	int i, sq, last, nod;
	N[0] = 1;
	nNum = 1;
	
	while(N[nNum - 1] < UB){
		last = N[nNum - 1];
		nod = 0;
		sq = sqrt(last);
		for(i=1; i <= sq; i++){
			if (last % i == 0){
				nod++;
			}
		}
		nod = nod * 2;
		if(sq*sq == last){
			nod--;
		}
		N[nNum++] = last + nod;
	}
}

int query(int target){
	int left, right, middle;
	left = 0;
	right = nNum - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(N[middle] == target){
			return middle;
		}
		else if (N[middle] < target){
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return (left + right) >> 1;
}

int main(){
	int nTest, testk;
	int min, max, i;
	int left, right, nelem;

	findSeq();


printf("N[nNum-1]=%d\n",N[nNum-1]);
	for(i=0;i<20;i++){
		printf("%d ",N[i]);
	}
	printf("%d\n",nNum);

	
	scanf("%d",&nTest);
	testk = 1;
	
	
	while(testk <= nTest){
		scanf("%d %d", &min, &max);
		left = query(min);
		right = query(max);
		if(N[left] == min){
			nelem = right - left + 1;
		}
		else{
			nelem = right - left;
		}
		printf("Case %d: %d\n", testk, nelem);
		testk++;
	}	
	
	return 0;
}
