#include <stdio.h>
#define MAXCHAR 1024

int main(){
	int g=34943;
	unsigned int CRC=0,uCRC,lCRC;
	char c;
	char line[MAXCHAR];
	int i,count;
	unsigned int r,q;
	
	while(scanf("%c",&c)){
		if('#' == c) return 0;
		
		count=0;
		while('\n' != c){
			line[count] = c;
			count++;
			scanf("%c",&c);
		}
		r = 0;
		for(i=0;i<count;i++){
			r = ((r << 8) + line[i]) % g;
		}	
		
		q = (r << 16)/g;
		CRC = (g*(q+1) - (r<<16)) % g;
		uCRC = (CRC &0xff00) >> 8;
		lCRC = CRC &0x00ff ;
		printf("%X%X ",uCRC>>4,(uCRC & 0xF));
		printf("%X%X\n",lCRC>>4,(lCRC&0xF));	
	}
	return 0;
}