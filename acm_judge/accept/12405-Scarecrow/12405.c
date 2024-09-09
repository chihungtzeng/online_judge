#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 110

int solve(int len, char farm[LEN]){
    int nScarecrow = 0;
    int count = 0;
    int i;
    
    for(i=1; i<len; i++){
        if ((farm[i] == '#') && (farm[i-1] == '.') && (farm[i+1] == '.')){
            farm[i] = '.';
        }
    }    
    
    for(i=1; i<=len; i++){
        if(farm[i] == '.'){
            count++;
        }
        else {
            nScarecrow += (count / 3) + (count % 3 == 0? 0 : 1);
            count = 0;
        }
    }
    nScarecrow += (count / 3) + (count % 3 == 0? 0 : 1);
    
    return nScarecrow;
}

int main(){
    int nTest, k = 1, len, nScarecrow;
    char farm[LEN];
    farm[0] = '\0';
    scanf("%d", &nTest);
    while(nTest--){
        scanf("%d %s", &len, farm + 1);
        nScarecrow = solve(len, farm);
        printf("Case %d: %d\n", k++, nScarecrow);
        
    }
    return 0;
}