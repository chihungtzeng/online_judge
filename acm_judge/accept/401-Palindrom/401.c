#include <stdio.h>
#include <string.h>
#define LEN 32

char mirrorChar[255];

void buildMirrorChar(){
	memset(mirrorChar, 0, 255);
mirrorChar['A'] = 'A';
mirrorChar['E'] = '3';
mirrorChar['H'] = 'H';
mirrorChar['I'] = 'I';
mirrorChar['J'] = 'L';
mirrorChar['L'] = 'J';
mirrorChar['M'] = 'M';
mirrorChar['O'] = 'O';
mirrorChar['S'] = '2';
mirrorChar['T'] = 'T';
mirrorChar['U'] = 'U';
mirrorChar['V'] = 'V';
mirrorChar['W'] = 'W';
mirrorChar['X'] = 'X';
mirrorChar['Y'] = 'Y';
mirrorChar['Z'] = '5';
mirrorChar['1'] = '1';
mirrorChar['2'] = 'S';
mirrorChar['3'] = 'E';
mirrorChar['5'] = 'Z';
mirrorChar['8'] = '8';
}

int isMirror(char *line, int len){
	int i, j;
	i=0; j = len - 1;
	while(i <= j){
		if(mirrorChar[line[i]] == 0){
			return 0;
		}
		if(mirrorChar[line[i]] != line[j]){
			return 0;
		}
		i++;
		j--;
	}
	return 1;
}

int isPalindrom(char *line, int len){
	int i, j;
	for(i=0, j=len - 1; i < j; i++, j--){
		if(line[i] != line[j]){
			return 0;
		}
	}
	return 1;
}

int main(){
	char line[LEN], *p;
	int len;
	int bMirror, bPalindrom;
	buildMirrorChar();
	
	while(1 == scanf("%s", line)){
		len = 0;
		p = line;
		while(*p != '\0'){
			if(*p == '0') *p = 'O';
			p++;
			len++;
		}
		bMirror = isMirror(line, len);
		bPalindrom = isPalindrom(line, len);
		if(bMirror){
			if(bPalindrom){
				printf("%s -- is a mirrored palindrome.\n\n", line);
			} else {
				printf("%s -- is a mirrored string.\n\n", line);
			}
		} else {
			if(bPalindrom){
				printf("%s -- is a regular palindrome.\n\n", line);
			} else {
				printf("%s -- is not a palindrome.\n\n", line);
			}
		}		
	}
	return 0;
}