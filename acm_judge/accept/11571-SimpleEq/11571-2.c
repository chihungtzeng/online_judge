#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DEBUG 0
#define NOSOLUTION 2
#define UNCERTAIN 0
#define FOUND 1
#define EPSILON 1e-12
#define LLONG_MAX 9223372036854775807
#define TOLERANCE 1000


long long A, B, C;
long double a = 1, b, c, d;
const long double oneOverThree = 1.0/3.0;

int compareLLong(const void *a, const void *b){
	long long x, y;
	x = *(long long *)a;
	y = *(long long *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

long double f(long double x){
	
	
	return 1 + b/x + (c/x)/x + ((d/x)/x)/x;
	
	
}

long double myCubicRoot(long double x){
	if(x == 0) return 0;
	if(x < 0) return -powl(fabsl(x), oneOverThree);
	else return powl(x, oneOverThree);
}

long double mySquareRoot(long double x){
	if(x < 0){
		if(DEBUG){
			printf("error: call sqrt(%Lf), 0 is returned\n", x);
		}
		return -1;
	}
	else if (x == 0) return 0;
	else return sqrtl(x);
}

long long newtonMethod(long long left, long long right){
	long double fleft, fright, fmiddle, tmp;
	long long middle;
	long long ans;
	

	fleft = f(left + 0.0);
	fright = f(right + 0.0);
	if(fabsl(fright) < EPSILON) return right;
	if(fabsl(fleft) < EPSILON) return left;
	
	/*No we have odd number of roots in [left right], we must return a best answer to it*/
	while(left <= right){
		if(fabsl(fright) < EPSILON) return right;
		if(fabsl(fleft) < EPSILON) return left;
		middle = (left + right) / 2;
		fmiddle = f(middle + 0.0);
		/*if((middle != 0) && (B % middle == 0)) return middle;*/
		if(fabsl(fmiddle) < EPSILON) return middle;

		if( ((fmiddle < 0) && (fleft >0)) || ((fmiddle > 0) && (fleft < 0))){		
			right = middle - 1;
			fright = f(right + 0.0);
		}
		else if ( ((fmiddle < 0) && (fright >0)) || ((fmiddle > 0) && (fright < 0))){
			left = middle + 1;
			fleft = f(left + 0.0);
		}
		else{
			ans = newtonMethod(middle + 1, right -1);
			if(ans != LLONG_MAX) return ans;
			else return newtonMethod(left + 1, middle - 1);
		}
	}
	return LLONG_MAX;
}

long long findOneRoot(){
	/*try to solve cubic function a*x^3 + b*x^2 + c*x + d =0*/
	/*
		assume the three roots be alpha, beta, and gamma in ascending order
		=> |alpha| <= cubicRoot(B);
		=> Netwon's method should find one or two roots in [-alpha..alpha]
		=> If there is one root in the range, use Netwon's method to find it.
		   If not, then let  f(p) and f(q) be the local maximum/minimum. 
		   By the defintion of cubic function, beta falls in [p, q],
		   and beta is the only root in [p,q]. 
		   use netwon's method to find beta.
	*/
	long double left, right, s;
	long long ans;
	long long i, modulus;
	
	if(B == 1) return 1;	
	
	
	right = myCubicRoot(B) + 1; /*B is guaranteed to be > 0*/ 
	left = -right;
	
	if(DEBUG){
		printf("start 1st stage...[%Lf %Lf]\n",left, right);
	}
	ans = newtonMethod(left, right);
	return ans;
	
}

int main(){
	long long alpha, beta, gamma;
	long long sum;
	long long root[3];
	short nTest;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in9.txt", "r") : stdin;
	fscanf(fp, "%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%lld %lld %lld", &A, &B, &C);
		b = -A;
		c = ((long double)A*A - C)/2.0;
		d = -B;
		if(DEBUG){
			printf("\n");
			printf("A=%lld B=%lld C=%lld\n b=%Lf c=%Lf d=%Lf\n",A,B,C,b,c,d);
			
		}
		alpha = findOneRoot();
		if((alpha == LLONG_MAX) || (alpha == 0)){
			puts("No solution.");
		}
		else{
			long long s, t, u;
			s = A - alpha;
			
			t = B / alpha;
			u = sqrtl((long double)s*s - 4.0*t);
			
			beta = (s + u) / 2;
			if((beta == 0) || (B % beta != 0)) beta++;
			
			gamma = s - beta;
			
			sum = alpha*alpha + beta*beta + gamma*gamma;
			if(sum != C){
				puts("No solution.");
			} 
			else{
				root[0] = alpha;
				root[1] = beta;
				root[2] = gamma;
				qsort(root, 3, sizeof(long long), compareLLong);
				if(DEBUG){
					printf("Three roots: %lld %lld %lld\n",root[0], root[1], root[2]);
				}
				
				
				if( (root[0] == root[1]) || (root[1] == root[2])){
					puts("No solution.");
				} 
				
				else{
					printf("%lld %lld %lld\n",root[0], root[1], root[2]);
				}
				
			}
		}
	}
	return 0;
}