#include <stdio.h>
#include <stdlib.h>
#define MAX 128

int main(){
	short n, i, j, k=1, pos;
	char line[MAX];
	char output[MAX*2];
	char *c;
	while(NULL != fgets(line, MAX, stdin)){
		n = atoi(line);
		if(0 == n){
			break;
		}
		printf("Case %hd:\n",k++);
		printf("#include<string.h>\n");
		printf("#include<stdio.h>\n");
		printf("int main()\n");
		printf("{\n");
		for(i=0; i<n; i++){
			fgets(line, MAX, stdin);
			pos = 0;
			c = line;
			while( (*c != '\n') && (*c != '\0')){
				if(*c == '\\'){
					output[pos++] = '\\';
					output[pos++] = '\\';
				}
				else if (*c == '\"'){
					output[pos++] = '\\';
					output[pos++] = '\"';
				}
				else{
					output[pos++] = *c;
				}
				c++;
			} 
			output[pos] = '\0';
			printf("printf(\"%s\\n\");\n",output);
		}
		printf("printf(\"\\n\");\n");
		printf("return 0;\n");
		printf("}\n");
	}
	return 0;
}