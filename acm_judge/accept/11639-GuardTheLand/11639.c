#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) < (b)? (b) : (a))
#define MIN(a, b) ((a) < (b)? (a) : (b))

struct Rectangle{
	int x1, y1, x2, y2;
};

int main(){
	int nNight, x[2][2], y[2][2], k=1;
	struct Rectangle guard[2];
	int i, left, right, up, down, width, height;
	int strong, weak, unsecure;
	scanf("%d", &nNight);
	while(nNight--){
		for(i=0; i<2; i++){
			scanf("%d %d %d %d", &guard[i].x1, &guard[i].y1, &guard[i].x2, &guard[i].y2);
		}
		left = MAX(guard[0].x1, guard[1].x1);
		right = MIN(guard[0].x2, guard[1].x2);
		down = MAX(guard[0].y1, guard[1].y1);
		up = MIN(guard[0].y2, guard[1].y2);
		width = MAX(right - left, 0);
		height = MAX(up - down, 0);
		strong = width * height;
		
		weak = 0;
		for(i=0 ; i<2; i++){
			weak += (guard[i].x2 - guard[i].x1)*(guard[i].y2 - guard[i].y1); 
		}
		weak = weak - strong*2;
		
		unsecure = 10000 - weak - strong;
		printf("Night %d: %d %d %d\n",k++, strong, weak, unsecure); 
	}
	return 0;
}