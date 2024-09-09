#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 10000

void solve(char *line){
    int len;
    len = strlen(line);

    if( !strcmp(line, "1") || !strcmp(line, "4") || !strcmp(line, "78")){
        printf("+\n");
        return ;
    }    
    if(len < 2){
        return ;
    }
    
    if (!strncmp(line + len - 2, "35", 2)){
        printf("-\n");
        return ;
    }
    if ((line[0] == '9') && (line[len - 1] == '4')){
        printf("*\n");
        return;
    }
    if (!strncmp(line, "190", 3)){
        printf("?\n");
        return ;
    }
    
}

int main(){
    int nTest;
    char *line;
    
    line = (char *) malloc(sizeof(char)*LEN);
    scanf("%d", &nTest);
    while(nTest--){
        scanf("%s", line);
        solve(line);
    }
    free(line);
    return 0;
}