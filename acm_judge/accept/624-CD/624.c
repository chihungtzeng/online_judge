#include <stdio.h>

#define NUM_TRACK 22
int myPow2[NUM_TRACK];

void solve(int length, int nTrack, int track[]){
    int best = 0, curCost, bestChoice=0;
    int i, count, bound;
    int select;
    
    bound = myPow2[nTrack + 1] - 1;
    
    for(select = bound; select >= 0; select--){
        curCost = 0;
        
        for(i=0; i< nTrack; i++){
            if(select & myPow2[i]){
                curCost += track[i]; 
            }
        }
        if((curCost > best) && (curCost <= length)){
            best = curCost;
            bestChoice = select;
        }
    }
    
    for(i=0; i<nTrack; i++){
        if(myPow2[i] & bestChoice){
            printf("%d ", track[i]);
        }
    }
    printf("sum:%d\n", best);

}

int main(){
    int length;
    int nTrack;
    int track[NUM_TRACK];
    int i;
    FILE *fp = stdin;
    
    for(i=0; i<NUM_TRACK; i++){
        myPow2[i] = 1 << i;
    }    
    
    
    while(2 == fscanf(fp, "%d %d", &length, &nTrack)){
        for(i=0; i<nTrack; i++){
            fscanf(fp, "%d", &track[i]);
        }
        solve(length, nTrack, track);
    }
    return 0;
}