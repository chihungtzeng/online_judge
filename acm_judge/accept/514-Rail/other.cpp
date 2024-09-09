#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
short myleft[1024], stack[1024];
short pmyleft, pstack, pright;

int main(){

    short block, n;

    bool first = true;

    while (true) {

       if (!first) printf("\n");

       first = false;

       scanf("%hd", &n);

       if (!n) return 0;

       while (true) {

           pright = 1;

           pmyleft = 0;

           pstack = -1;

           scanf("%hd", myleft);

           if (!myleft[0]) break;

           for (int i = 1; i < n; i++)

              scanf("%hd", myleft + i);

           while (pright <= n) {

              if (pright == myleft[pmyleft]) {

                  pright++;

                  pmyleft++;

              } else if (pstack >= 0 && stack[pstack] == myleft[pmyleft]) {

                  pstack--;

                  pmyleft++;

              } else {

                  stack[++pstack] = pright++;

              }

           }

           while(pstack >= 0 && stack[pstack] == myleft[pmyleft]) {

                  pstack--;

                  pmyleft++;

           }

           if (pstack == -1) printf("Yes\n");

           else printf("No\n");

       }

    }
	return 0;
}