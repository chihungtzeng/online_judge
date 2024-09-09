#include <stdio.h>

long long solve(int n){
    long long w;
       
    if (n == 0) return 1;
    
    w = n >> 1;
    w = (w+1)*(w+2)>>1;
    return w;
}

int main(){
    int n;
    long long ans;
    while(1 == scanf("%d", &n)){
        ans = solve(n);
        printf("%lld\n", ans);
    }
    return 0;
}