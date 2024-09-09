#include <stdio.h>

#define MAX 20

int main(){
    int side[3];
    int fit;
    int k=1, i;
    
    scanf("%d", &k);
    k=1;
    while(3 == scanf("%d %d %d", &side[0], &side[1], &side[2])){
        fit = 1;
        for(i=0; i<3; i++){
            if(side[i] > MAX) fit = 0;
        }
        
        printf("Case %d: %s\n", k++, fit? "good" : "bad");
    }
        
    
    return 0;
}