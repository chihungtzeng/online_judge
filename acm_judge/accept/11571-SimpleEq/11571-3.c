/*AC 0.012 C++*/
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
#define MINMAX_BOUND 1
#define TRIVIAL_BOUND 2


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
	long double p, q, r, s;
	if(fabs(x) < EPSILON) return d;
	
	p = b/x;
	q = (c/x)/x ;
	r = ((d/x)/x)/x;
	s = 1 +p +q +r;
	if(x > 0) return s;
	else return -s;
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

long long newtonMethod(long long left, long long right, int type){
	long double fleft, fright, fmiddle;
	long double fxleft, fxright, fxmiddle;
	long long middle;
	long double min = LLONG_MAX;
	long long bestAns;
	

	fleft = f(left + 0.0);
	fright = f(right + 0.0);

	if ((fabsl(fleft) < EPSILON) ){
		return left;
	}
	
	if ((fabsl(fright) < EPSILON)){
		return right;
	}
	
	if( (((fleft > 0) && (fright > 0)) || ((fleft < 0) && (fright < 0))) && (type == TRIVIAL_BOUND)){
			if(DEBUG){
					printf("abort: [left, right] = [%lld %lld] contains even number of roots\n",left, right);
					printf("f(%lld) = %.15Lf f(%lld) = %.15Lf\n",left, fleft, right, fright);
				}
			return LLONG_MAX;
	}
	
	
		
	/*No we have odd number of roots in [left right], we must return a best answer to it*/
	while(left <= right){
		middle = (left + right)/2 ;
		fmiddle = f(middle + 0.0);	

		if(fabsl(fmiddle) < min){
			min = fabsl(fmiddle);
			bestAns = middle;
		}
		if(fabsl(fright) < min){
			min = fabsl(fright);
			bestAns = right;
		}
		if(fabsl(fleft) < min){
			min = fabsl(fleft);
			bestAns = left;
		}

		if( ((fmiddle < 0) && (fleft >0))){		
			right = middle - 1;
			fright = f(right + 0.0);
		}
		else if ((fmiddle > 0) && (fleft < 0)){
			right = middle - 1;
			fright = f(right + 0.0);
		}
		else if (((fmiddle < 0) && (fright >0)) ){
			left = middle + 1;
			fleft = f(left + 0.0);
		}
		else if ((fmiddle > 0) && (fright < 0)) {
			left = middle + 1;
			fleft = f(left + 0.0);
		}
		else{
			if(min < TOLERANCE) return bestAns;
			else return LLONG_MAX;
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
	
	
	right = myCubicRoot(B) - 1; /*B is guaranteed to be > 0*/ 
	left = -right;
	
	if(DEBUG){
		printf("start 1st stage...[%Lf %Lf]\n",left, right);
	}
	ans = newtonMethod(left, right, TRIVIAL_BOUND);
	if(ans != LLONG_MAX){
		return ans;
	}	
	/*easy case does not happen, find local maximum/minimum*/
	s = mySquareRoot(b*b - 3*c);
	if(s < 0){
		/*b^2 - 3c < 0. Impossible*/
		return LLONG_MAX;
	}
	left = (-b - s)/3;
	right = (-b + s)/3;
	if(DEBUG){
		printf("start 2nd stage...[%Lf %Lf]\n",left, right);
	}
	ans = newtonMethod(left, right, MINMAX_BOUND);
	

	return ans;
	
}

int checkAns(long long root[], long long alpha){
	long double sq;
	long long beta, gamma;
	long long s, t, u;
	long long sum;
	
	if((alpha == LLONG_MAX) || (alpha == 0)){
			return EXIT_FAILURE;
	}
	if (B % alpha != 0) return  EXIT_FAILURE;
	
	s = A - alpha;
	t = B / alpha;
	
	sq = (long double)s*s - 4.0*t;
	if(sq < 0) return EXIT_FAILURE;
	u = mySquareRoot(sq);
	
	beta = (s + u) / 2;
	if((beta == 0) || (B % beta != 0)) beta++;
	
	gamma = s - beta;

	
	
	sum = alpha*alpha + beta*beta + gamma*gamma;
	if((sum != C) || (alpha * beta * gamma != B)){
		return EXIT_FAILURE;
	} 
	
	root[0] = alpha;
	root[1] = beta;
	root[2] = gamma;
	qsort(root, 3, sizeof(long long), compareLLong);
	if(DEBUG){
		printf("Three roots: %lld %lld %lld\n",root[0], root[1], root[2]);
	}
	
	
	if( (root[0] == root[1]) || (root[1] == root[2])){
		return EXIT_FAILURE;
	} 		
	else{
		return EXIT_SUCCESS;
	}
} 

int main(){
	long long root[3], alpha, i, candidate;
	int state;
	
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
		if(DEBUG){
			printf("findOneRoot returns alpha = %lld\n",alpha);
		}
		state = checkAns(root, alpha);
		if(state == EXIT_SUCCESS){
			printf("%lld %lld %lld\n",root[0], root[1], root[2]);
			continue;
		}
		for(i = -3; (i<=3) && (state == EXIT_FAILURE); i++){
			candidate = alpha + i;
			state = checkAns(root, candidate);
			if(state == EXIT_SUCCESS){
				printf("%lld %lld %lld\n",root[0], root[1], root[2]);
			}
		}
		if(state == EXIT_FAILURE){
			puts("No solution.");
		}
	}
	return 0;
}