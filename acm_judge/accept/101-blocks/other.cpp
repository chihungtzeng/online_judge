#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;



class block{
int num;
block* next;
block* last;

block(int num){ this->num=num; next=0; last=0;}
friend class blockWorld;
};


class blockWorld{
block** blockMap; 
block** getBlockAddr; 
int n; 

public:
blockWorld(int n);
void print();
void addTail(int x, int y);
void clearTail(int x);
int isTheSameStack(int x, int y);
};



blockWorld::blockWorld(int n){
this->n = n;
blockMap = new block*[n];
getBlockAddr= new block*[n];
for(int i=0;i<n;i++){
blockMap[i] = new block(i);
getBlockAddr[i] = blockMap[i];
}
}


void blockWorld::print(){
block* p;
for(int i=0;i<n;i++){
printf("%d:",i);

p = blockMap[i];
while(p){
printf(" %d",p->num);
p=p->next;
}
printf("\n");
}
}


void blockWorld::addTail(int x, int y){
block* p = getBlockAddr[y];
block* px = getBlockAddr[x];
while(p->next){
p=p->next;
}
p->next = px;
if(px->last) px->last->next = 0;
else blockMap[px->num] = 0;
px->last = p;
}


void blockWorld::clearTail(int x){

block* px = getBlockAddr[x];
block* p = px->next;
px->next=0;

while(p){
int num = p->num;
if(blockMap[num]){
block* w=blockMap[num];
while(w->next)
w = w->next;
w->next=p;
p->last=w;
}else{ 
blockMap[num] = p;
p->last=0;
}

block* q = p->next;
p->next = 0;
p=q;
}
}

int blockWorld::isTheSameStack(int x,int y){
block* p = getBlockAddr[x]->next;
while(p){
if(y == p->num) return 1;
p=p->next;
}

p = getBlockAddr[x]->last;
while(p){
if(y==p->num) return 1;
p=p->last;
}
return 0;
}


int main()
{
char command1[10], command2[10];
int a,b;
int n; 
cin>>n;

blockWorld bw(n);


while(1){


cin >> command1;
if(strcmp(command1,"quit")==0) break;
cin >> a;
cin >> command2;
cin >> b;


if(a==b) continue;
if(bw.isTheSameStack(a,b)==1) continue;


if(strcmp(command1,"move")==0)
bw.clearTail(a);


if(strcmp(command2,"onto")==0)
bw.clearTail(b);

bw.addTail(a,b);
}
bw.print();
return 0;
}
