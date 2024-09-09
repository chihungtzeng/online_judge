#include <stdio.h>
#include <string.h>

#define MAX 102
#define DEBUG 0

int isStar(char sky[MAX][MAX], int row, int col){
    int i, j;
    if(sky[row][col] != '*'){
        return 0;
    }
    for(i=-1; i<=1; i++){
        for(j=-1; j<=1; j++){
            if(!i && !j) {
                continue;
            }
            if(sky[row+i][col+j] == '*') return 0;
        }
    }
    #if DEBUG
    printf("star: row=%d, col=%d\n", row, col);
    #endif
    return 1;
}

int calcAns(char sky[MAX][MAX], int nRow, int nCol){
    int ans = 0;
    int i, j;
    for(i=1; i<=nRow; i++){
        for(j=1; j<=nCol; j++){
           ans += isStar(sky, i, j);
           
        }
    }
    return ans;
}

int main(){
    char sky[MAX][MAX];
    int nRow, nCol;
    int i;
    FILE *fp = (DEBUG)? fopen("in.txt","r") : stdin;

    for(i=0; i<MAX; i++){
        memset(sky[i], 0, MAX);
    }
    while(2 == fscanf(fp, "%d %d", &nRow, &nCol)){
        if(!nRow && !nCol){
            break;
        }
        for(i=1; i<=nRow; i++){
            fscanf(fp, "%s", sky[i] + 1);
        }
        memset(sky[nRow+1], 0, MAX);
        #if DEBUG
        for(i=1; i<=nRow; i++){
            printf("%s\n", sky[i] + 1);
        }
        #endif
        printf("%d\n", calcAns(sky, nRow, nCol));
    }    
    
    return 0;
}