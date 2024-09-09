#include <stdio.h>
#include <string.h>

#define MAX 255
#define HIGH_QUALITY 0
#define LOW_QUALITY 1

int main(){
    int nTest, kase=1, i, j, ans;
    int nRow, nCol;
    int nByte[2];
    char freq[MAX];
    char line[MAX];
    int mostFreq, nHighQuality;
    
    scanf("%d", &nTest);
    while(nTest--){
        scanf("%d %d %d %d",&nRow, &nCol, &nByte[HIGH_QUALITY], &nByte[LOW_QUALITY]);
        memset(freq + 'A', 0, 26);
        for(i=0; i<nRow; i++){
            scanf("%s", line);
            for(j=0; j<nCol; j++){
                freq[line[j]] += 1;
            }
        }
        for(i='A', mostFreq = 0; i<='Z'; i++){
            if(freq[i] > mostFreq) {
                mostFreq = freq[i];
            }
        }
        for(i='A', nHighQuality =0; i<='Z'; i++){
            if(freq[i] == mostFreq){
                nHighQuality += freq[i];
            }
        }
        ans = nHighQuality * nByte[HIGH_QUALITY] + (nRow * nCol - nHighQuality) * nByte[LOW_QUALITY];
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}