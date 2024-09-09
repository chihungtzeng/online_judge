#include<stdio.h>


char F[101][101];
char N, P;

char Gcd(char a, char b) {
	char temp;
   while ( b > 0 )  {
     temp = a % b;
     a = b;
     b = temp;
   }
   return a;  
}

void Ini(){
        char i, j, k;
        for(i = 2; i<101; i++) {
                for(j = i; j<101; j++){
                        k = Gcd(i,j);
                        if(k>1)
                                F[i][j] = F[j][i] = 1;
                }
        }
}

char A[102];

void Print() {
        char i;
        printf("%hhd",A[1]);
        for(i = 2; i<=P; i++)
                printf(" %hhd",A[i]);
        printf("\n");
}

void Recur(char n, char sum, char level) {
        char i, j, s, d, k;
        short left;
        A[level] = n;
        if(level+1 == P) {
                d = N - sum;
                if(d<= n) return;
                for(k = 1; k<= level; k++)
                        if(F[d][A[k]]) break;
                if(k<=level) return;
                if(sum+d == N){
                        A[level+1] = d;
                        Print();
                }
                return;
        }
        s = (n<=1)?1:n+1;
        for(i = s; ; i++) {
                d = P - level;
                j = i+d-1;
                left = ((i+j)*d) >> 1;
                if(i == 1) left = 1;
                if(sum + left> N) return;
                for(k = 1; k<=level; k++)
                        if(F[i][A[k]] == 1) break;
                if(k <= level) continue;
                Recur(i,sum+i,level+1);
        }
}

void Cal() {
	char i;
  if(P == 1) {
       printf("%hhd\n",N);
       return;
  }
  if(P == N) {
       printf("1");
       for(i = 1; i<P; i++)
               printf(" 1");
       printf("\n");
  }
  Recur(0,0,0);
}

int main() {
  char ks, k = 1;
  Ini();
  scanf("%hhd",&ks);
  while(ks--) {
          scanf("%hhd %hhd",&N,&P);
          printf("Case %hhd:\n",k++);
          Cal();
  }
	return 0;
}