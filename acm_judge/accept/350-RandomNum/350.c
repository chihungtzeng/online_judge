#include <stdio.h>
#include <string.h>
#define LEN 10000
#define TRUE 1
#define FALSE 0

char alreadyShown[LEN];
short elementAt[LEN];
int Z, I, L, M;

int solve(){
	char done = 0;
	short i, index=0;
	int result;
	long long nextNum;
	
	
	memset(alreadyShown, FALSE, LEN);
	elementAt[L] = 0;
	alreadyShown[L] = TRUE;
	#if 0
	printf("Z=%d L=%d I=%d M=%d\n", Z, L, I, M);
	#endif
	while(!done){
		nextNum = ( (long long)Z * L + I) % M;
		index++;
		#if 0
		printf("%lld\n", nextNum);
		#endif
		if(alreadyShown[nextNum] == TRUE){
			done = TRUE;
			result = index - elementAt[nextNum];
		} else{
			L = nextNum;
			alreadyShown[L] = TRUE;
			elementAt[L] = index;
		}
	}
	return result;
}

int main(){
	int k = 1, ans;
	while(4 == scanf("%d %d %d %d", &Z, &I, &M, &L)){
		if((0 == Z) && (0 == I) && (0 == L) && (0 == M)){
			break;
		}
		ans = solve();
		printf("Case %d: %d\n", k++, ans);
	}
	return 0;
}