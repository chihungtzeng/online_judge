#include <stdio.h>

int main(){
	FILE *fp;
	char symb[2], code[10];
	fp = fopen("table.txt","r");
	while(2 == fscanf(fp, "%s %s",symb, code)){
		printf("{'%s', \"%s\"} ",symb, code);
	}
	fclose(fp);
}