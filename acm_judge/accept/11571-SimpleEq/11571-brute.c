#include <stdio.h>
#include <math.h>
#define NOSOLUTION 2
#define UNCERTAIN 0
#define FOUND 1


long long A, B, C, D;
const long double oneOverThree = 1.0/3.0;

long long perfectSquare(long long x){
	long long q;
	if(x < 0) return -1;
	q = sqrtl(x);
	if(q*q == x) return q;
	else return -1;
}

int compareLLong(const void *a, const void *b){
	long long x, y;
	x = *(long long *)a;
	y = *(long long *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

int testRoot(long long a, long long t[3]){
	long long b, c;
	t[0] = a - A;
	t[1] = B / a;
	D = t[0]*t[0] - 4*t[1] ;
	t[2] = perfectSquare(D);
	if(t[2] >= 0){		
		b = (-t[0] + t[2])/2;
		c = (-t[0] - t[2])/2;
		if(a*a + b*b + c*c == C){
			t[0] = a;
			t[1] = b;
			t[2] = c;
			qsort(t, 3, sizeof(long long), compareLLong);
			if((t[0] == t[1]) || (t[1] == t[2])){
				printf("No solution.\n");
				return NOSOLUTION;
			}
			else{
				printf("%lld %lld %lld\n", t[0], t[1], t[2]);
				return FOUND;
			} 
		}
	}
	return UNCERTAIN;
}

long long findOneRoot(){
	long long a;
	long long t[3];
	int state;
	
	a = powl(B, oneOverThree);
	t[0] = 4*A*A - 8*(A*A - C);
	if(perfectSquare(t[0]) > 0){
		t[1] = (2*A + t[0]) / 4;
		t[2] = (2*A - t[0]) / 4;
		if(t[1]*t[1] + t[2]*t[2] == C){
			qsort(t, 3, sizeof(long long), compareLLong);
			if( (t[0] == t[1]) || (t[1] == t[2])){
				printf("No solution.\n");
			}
			else{
				printf("%lld %lld %lld\n", t[0], t[1], t[2]);
			}
			return 0;
		}
	}
	
	
	while(a > 0){
		if(B % a == 0){
			if(testRoot(a, t) != UNCERTAIN) return 0;
			if(testRoot(-a, t) != UNCERTAIN) return 0;
		}
		a--;
	}
	printf("No solution.\n");
	
	return 0;
}

int main(){
	long long x, y, z;
	short nTest;
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%lld %lld %lld", &A, &B, &C);
		findOneRoot();
	}
	return 0;
}