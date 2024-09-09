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
    
        
    tmp[0] = ell*(ell+1) >> 1;
    tmp[0] = tmp[0]*(2*ell + 1) / 3;
    tmp[0] = tmp[0] % MOD;
    tmp[1] = (ellprime + 1)*(((ellprime - 1) >> 1) + 1) >> 1;
    tmp[1] = tmp[1] % MOD;
    tmp[2] = (r % MOD) * (q % MOD) % MOD;
    ans = 0;
    for(q=0; q<3; q++){
        #if 0
        printf("tmp[%lld] = %lld\n", q, tmp[q]);
        #endif
        ans += tmp[q];
        ans = ans % MOD;
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
