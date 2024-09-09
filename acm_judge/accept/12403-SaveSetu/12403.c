#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 64

int main(){
    int nOp, i;
    char line[LEN], *amount;
    int donate;
    FILE *fp = stdin;    
    
    while(NULL != fgets(line, LEN, fp)){
        nOp = atoi(line);
        
        donate = 0;
        for(i=0;i<nOp; i++){
            fgets(line, LEN, fp);
            if(line[0] == 'r'){
                printf("%d\n", donate);
            }   
            else{
                amount = strtok(line, " ");
                amount = strtok(NULL, " ");
                
                donate += atoi(amount);
                
            }
        }
    }
    return 0;
}