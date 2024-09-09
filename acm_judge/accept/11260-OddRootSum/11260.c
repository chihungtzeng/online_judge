#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 100000000


void solve(long long m){
    long long q;
    long long ell, ans, s;
    long long ellprime;
    long long r; /* #remaining numbers whose square roots are q*/
    long long firstEleInLastSeq;
    long long tmp[3];
    
    q = sqrt(m);
    ell = q - 1;
    ellprime = (ell & 1)? ell : ell - 1;
    
    firstEleInLastSeq = q * q;

    if(firstEleInLastSeq % 2 == 0){
        firstEleInLastSeq++;
    }
    r = ((m - firstEleInLastSeq) >> 1) + 1;
    
    #if 1
    printf("m=%lld, q=%lld, ell=%lld, ellprime=%lld, r=%lld\n", m, q, ell, ellprime, r);
    #endif
    
        
    tmp[0] = ell*(ell+1)*(2*ell + 1) / 6;
    tmp[1] = (ellprime + 1)*((ellprime - 1)/2 + 1) >> 1;
    tmp[2] = r * q;
    ans = 0;
    for(q=0; q<3; q++){
    printf("tmp[%lld] = %lld\n", q, tmp[q]);
    ans+=tmp[q];
    }

    printf("%lld\n", ans);
    
}


int main(){
    long long n, m;
    while(1 == scanf("%lld", &n)){
        if(n <= 0) {
            break;
        }
        m = (n & 1)? n : n-1;
        solve(m);
    }
    
    return 0;
}
