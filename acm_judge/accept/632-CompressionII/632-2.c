#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 2048
#define DEBUG 0

struct Line {
    char text[LEN];
    int lineno;
};


int compareLine(const void *a, const void *b){
    struct Line *x, *y;
    int nStrcmp;
    x = (struct Line *)a;
    y = (struct Line *)b;
    nStrcmp = strcmp(x->text, y->text);
    
    if(nStrcmp != 0){
        return nStrcmp;
    }
    else{
        return x->lineno - y->lineno;
    }
}

void solve(int length, char input[LEN], struct Line *lines){
    int i, j, i_1;
    int s1pos = 1;
    char output[LEN];
    struct Line s1;
    int nCharOut;
    char outputLine[51];
    
    
    #if DEBUG
    printf("length=%d\n", length);
    #endif
    strcpy(lines[0].text, input);
    for(i=0; i<length; i++){
        lines[i].lineno = i;
    }
    
    
    for(i=1; i<length; i++){
        i_1 = i - 1;
        for(j=length-2; j>=0; j--){
            lines[i].text[j] = lines[i_1].text[j+1];
        }
        lines[i].text[length-1] = lines[i_1].text[0];
        lines[i].text[length] = '\0';
    }
    memcpy(&s1, &lines[1], sizeof(struct Line));
    
    #if 0
    for(i=0; i<length; i++){
        printf("%s\n", lines[i].text);
    }
    printf("\n");
    #endif
    qsort(lines, length, sizeof(struct Line), compareLine);
    #if 0
    for(i=0; i<length; i++){
        printf("%s\n", lines[i].text);
    }
    #endif
    
    for(i=0; i<length; i++){
        if(lines[i].lineno == 1){
            s1pos = i;
            break;
        }
    }
    j = length - 1;
    for(i=0; i<length; i++){
        output[i] = lines[i].text[j];
    }
    output[length] = '\0';
    
    
    printf("%d\n", s1pos);
    
    for(nCharOut=0; nCharOut<length; nCharOut+=50){
        memcpy(outputLine, output + nCharOut, 50);
        outputLine[50] = '\0';
        printf("%s\n", outputLine);
    }
    
    
}

int main(){
    FILE *fp = (DEBUG)? fopen("in.txt", "r") : stdin;
    int nTest, length, nCharRead, n;
    char input[LEN];
    char line[LEN];
    
    int first = 1;
    struct Line *lines;
    
    lines = (struct Line *) malloc(sizeof(struct Line)*LEN);
    
    fgets(line, LEN, fp);
    nTest = atoi(line);
   
    
    while(nTest--){
        if (first){
            first = 0;
        }
        else{
            printf("\n");
        }
        fgets(line, LEN, fp);
        fgets(line, LEN, fp);
        length = atoi(line);
        
        nCharRead = 0;
        
        input[0] = '\0';
        while(nCharRead < length){
            fgets(line, LEN, fp);
            n = strlen(line);
            if (line[n-1] == '\n'){
                line[n-1] = '\0';
                
            }
            nCharRead += sprintf(input + nCharRead, "%s", line);
        }

        solve(length, input, lines);
    }
    free(lines);
    return 0;
}
