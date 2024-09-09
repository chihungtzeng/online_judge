#include <stdio.h>
#define N 508
#define NOTHING 0
#define SINGLES 1
#define RLE 2
short buf[N+4];
int pos=0, size=0;
void rebuf() {
	if (pos) {
		for (int i=pos;i<size;i++) {
			buf[i-pos]=buf[i];
		}
	}
	if (size) {
		int oldpos=pos;
		pos=size-pos;
		size-=oldpos;
	} else {
		pos=0;
		size=0;
	}
	char cbuf[N];
	int num=fread(cbuf, 1, N-size, stdin);
	char *c=cbuf;
	for (int i=0;i<num;i++) {
		buf[pos++]=*(c++);
	}
	pos=0;
	if (num<N-size) {
		/* append 256s */
		size+=num;
		buf[size]=buf[size+1]=buf[size+2]=256;
		size+=3;
	} else {
		size=N;
	}
}
short top(int off=0) {
	if (pos+off+1>size) {
		rebuf(); /* will change pos! */
	}
	return buf[pos+off];
}
void adv() {
	pos++;
}
int main() {
	int state=NOTHING;
	char pbuf[129];
	int num=0;
	short curr=0;
	while (1) {
		switch (state) {
			case NOTHING: {
				short a=top();
				short b=top(1);
				if (a==256) {
					return 0;
				}
				if (a==b) {
					num=0;
					curr=a;
					state=RLE;
				} else {
					num=0;
					state=SINGLES;
				}
				break;
			}
			case SINGLES: {
				if (num>=128||(top()==top(1)&&top()==top(2))) {
					printf("%c", num-1);
					char *pt=pbuf;
					for (int i=0;i<num;i++) {
						printf("%c", *(pt++));
					}
					state=NOTHING;
				} else {
					pbuf[num++]=top();
					adv();
				}
				break;
			}
			case RLE: {
				if (num>=128||top()!=curr) {
					printf("%c%c", num-2+129, curr);
					state=NOTHING;
				} else {
					num++;
					adv();
				}
				break;
			}
		}
	}
	return 0;
}
