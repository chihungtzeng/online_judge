#include <stdio.h>
#define MAX(a, b) ((a) < (b)? (b) : (a))
#define MIN(a, b) ((a) < (b)? (a) : (b))

struct Point{
	int x,y;
};

struct Rect{
	struct Point ll, ur;
};

struct Rect rect[2];

int lineIntersect(struct Point *p, int x11, int x12, int x21, int x22){
	/* [x11 x12] intersect  [x21 x22]*/
	if((x12 <= x21) || (x22 <= x11)) return 0;
	p->x = MAX(x11, x21);
	p->y = MIN(x12, x22);
	return 1;
}


void solve(){
	int state[2];
	struct Point xline, yline;
	state[0] = lineIntersect(&xline, rect[0].ll.x, rect[0].ur.x, rect[1].ll.x, rect[1].ur.x);
	state[1] = lineIntersect(&yline, rect[0].ll.y, rect[0].ur.y, rect[1].ll.y, rect[1].ur.y);
	if( !state[0] || !state[1]){
		printf("No Overlap\n");
	} else{
		printf("%d %d %d %d\n", xline.x, yline.x, xline.y, yline.y);
	}
}

int main(){
	int nTest;
	int first = 1;
	int i;
	scanf("%d", &nTest);
	while(nTest--){
		for(i=0; i<2; i++){
			scanf("%d %d %d %d", &rect[i].ll.x, &rect[i].ll.y, &rect[i].ur.x, &rect[i].ur.y);
		}
		if(first){
			first = 0;
		} else{
			printf("\n");
		}
		solve();
	}
	return 0;
}