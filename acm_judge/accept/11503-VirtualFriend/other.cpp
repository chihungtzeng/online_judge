#include<stdio.h>
#include<map>
#include<string>



using namespace std;

#define maxn 100003

map<string,int>mp;

int Rank[maxn], P[maxn];


void Ini(int n) {
        int i;
        for(i = 0; i<= maxn; i++) {
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
        int total = 0, i, parent1 , parent2 ;
        char name1[100], name2[100];
        while(n--) {
                scanf("%s%s",name1,name2);

                int node1 = mp[name1];
                int node2 = mp[name2];
               
                if(node1 == 0) {
                        parent1 = ++total;
                        mp[name1] = parent1;
                }else {
                        parent1 = findParent(node1);
                }
                if(node2 == 0) {
                        parent2 = ++total;
                        mp[name2] = parent2;
                }else {
                        parent2 = findParent(node2);
                }
                if(parent1 != parent2) {
                        printf("%d\n",Rank[parent1] + Rank[parent2]);
                        makeLink(parent1,parent2);
                }else {
                        printf("%d\n",Rank[parent1]);
                }
        }
        mp.clear();
}

int main() {
        int kase, n;
        scanf("%d",&kase);
        while(kase--) {
                scanf("%d",&n);
                Ini(n);
                Cal(n);
        }
        return 0;
} 