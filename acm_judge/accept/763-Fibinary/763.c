#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128
#define DEBUG 0

char a[MAX], b[MAX], c[MAX];
short alen, blen, clen;
short next[MAX];
short pre[MAX];

void reverse(char s[], short len){
	short i, tmp;
	for(i=len/2 - 1; i>=0; i--){
		tmp = len - i - 1;
		s[i] = s[i] ^ s[tmp];
		s[tmp] = s[i] ^ s[tmp];
		s[i] = s[i] ^ s[tmp];
	} 
}

short smooth(char c[], short len){
	short pos = pre[len];
	short left, right;
	short max = len, result;
	short i;
	char done = 0;
	
	while(!done){
		done = 1;
		if(c[0] >= 2){
			c[1] += c[0] >> 1;
			c[0] = c[0] & 1;
			done = 0;
		}
		if(c[1] >= 2){
			c[2] += c[1] >> 1;
			c[0] += c[1] >> 1;
			c[1] = c[1] & 1;
			done = 0;
		}
		for(i=2; i<max; i++){
			if(c[i] >= 2){
				c[next[i]] += c[i] >> 1;
				c[pre[pre[i]]] += c[i] >> 1;
				c[i] = c[i] % 2;
				done = 0;
			}
		}
		if(c[max] >= 1) max++;
	}

	done = 0;
	while(!done){
		done = 1;
		for(pos = pre[max]; pos >= 1; pos--){
			if( (c[pos] == 1) && (c[pre[pos]] == 1)){
				c[next[pos]] = 1;
				c[pos] = 0;
				c[pre[pos]] = 0;
				done = 0;
			}
		}
		if(c[max] == 1) max++;
	}
	
	return max;
}

void add(){
	short i, j;
	short max;
	for(i=0; i<alen; i++){
		a[i] = a[i] - '0';
	}
	for(i=0; i<blen; i++){
		b[i] = b[i] - '0';
	}
	for(i=0; i<MAX;i++){
		pre[i] = i - 1;
		next[i] = i + 1;
	}
	reverse(a, alen);
	reverse(b, blen);
	
	clen = (alen > blen)? alen : blen;
	for(i=0; i<clen; i++){
		c[i] = a[i] + b[i];
	}
	
	clen = smooth(c, clen);
	for(i=0; i<clen; i++){
		c[i] = c[i] + '0';
	}
	reverse(c, clen);
}

int main(){
	char first = 1;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in2.txt","r"):stdin;
	memset(a, 0, MAX);
	memset(b, 0, MAX);
	memset(c, 0, MAX);
	while(2 == fscanf(fp, "%s %s", a, b)){
		
		alen = strlen(a);
		blen = strlen(b);
		add();
		
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		puts(c);
		memset(a, 0, MAX);
		memset(b, 0, MAX);
		memset(c, 0, MAX);
	}
	
	return 0;
}
