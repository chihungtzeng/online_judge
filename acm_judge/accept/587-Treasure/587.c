#include <stdio.h>
#include <string.h>
#include <math.h>
#define LEN 65536


int main(){
	char line[LEN];
	double x, y, dist;
	char direction[3];
	char *tok;
	int i, len, length, k =1;	
	FILE *fp = stdin;
	const double SQRT2 = sqrt(2);
	while(NULL != fgets(line, LEN, fp)){
		
		len = strlen(line);
		if(line[len - 1] == '\n'){
			len--;
			line[len] = '\0';
		}
		if(!strcmp(line, "END")) return 0;
				
			
		x = 0;
		y = 0;
		tok = strtok(line, ",.");
		while(tok != NULL){
			sscanf(tok, "%d%s", &length, direction);
			dist = (double) length;
			if(!strcmp(direction, "N")){
				y += dist;
			}
			else if(!strcmp(direction, "NE")){
				dist = dist/SQRT2;
				x += dist;
				y += dist;
			}
			else if(!strcmp(direction, "E")){
				x += dist;
			}
			else if(!strcmp(direction, "SE")){
				dist = dist/SQRT2;
				x += dist;
				y -= dist;
			}
			else if(!strcmp(direction, "S")){
				
				
				y -= dist;
			}
			else if(!strcmp(direction, "SW")){
				dist = dist/SQRT2;
				x -= dist;
				y -= dist;
			}
			else if(!strcmp(direction, "W")){
				
				x -= dist;
				
			}
			else if(!strcmp(direction, "NW")){
				dist = dist/SQRT2;
				x -= dist;
				y += dist;
			}
			tok = strtok(NULL, ",.");
		}
		dist = sqrt(x*x + y*y);
		
		printf("Map #%d\n",k++);
		printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
		printf("The distance to the treasure is %.3lf.\n\n",dist);
	}
	return 0;
}