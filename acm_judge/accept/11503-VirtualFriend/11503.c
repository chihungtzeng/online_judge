#include<stdio.h>
#include <string.h>
#include <search.h>
#include <stdlib.h>
#define MAX 100010
#define DEBUG 0

struct Map{
	char name[100];
	int id;
};

struct Map *newMap(char name[], int id){
	struct Map *m;
	m = (struct Map *) malloc(sizeof(struct Map));
	strcpy(m->name, name);
	m->id = id;
	return m;
}

int compareMap(const void *a, const void *b){
	struct Map *x, *y;
	x = (struct Map *) a;
	y = (struct Map *) b;
	return strcmp(x->name, y->name);
}

int Rank[MAX], P[MAX];
FILE *fp;


void Ini(int n) {
        int i;
        for(i = 0; i< MAX; i++) {
                Rank[i] = 1;
                P[i] = i;
        }
}

int findParent(int u)  {
        if(u == P[u]) return u;
        else {
                P[u] =  findParent(P[u]);
                return P[u];
        }
}

void makeLink(int u, int v) {
        if(Rank[u] > Rank[v]) {
                P[v] = u;
                Rank[u] += Rank[v];
        }else {
                P[u] = v;
                Rank[v] += Rank[u];
        }
}



void Cal(int n) {
     int total = 0, i, parent[2];
     char name[2][100];
     int node[2];
     void *root, *match;
     struct Map *map;

		root = NULL;     
     while(n--) {
       fscanf(fp, "%s %s",name[0],name[1]);

		/*
       int node1 = mp[name1];
       int node2 = mp[name2];
      */
      
     	for(i=0; i<2; i++){
     		map = newMap(name[i], -1);
     		match = tfind(map, &root, compareMap);
     		if(!match){
				parent[i] = ++total;
				map->id = parent[i];
				tsearch(map, &root, compareMap);
			}
			else{
				free(map);
				map = *(struct Map **) match;
				parent[i] = findParent(map->id);
			}
     	}

       if(parent[1] != parent[0]) {
               printf("%d\n",Rank[parent[0]] + Rank[parent[1]]);
               makeLink(parent[0],parent[1]);
       }else {
               printf("%d\n",Rank[parent[0]]);
       }
     }
     tdestroy(root, free);
}

int main() {
  int kase, n;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
  fscanf(fp, "%d",&kase);
  while(kase--) {
       fscanf(fp, "%d",&n);
       Ini(n);
       Cal(n);
  }
  return 0;
} 