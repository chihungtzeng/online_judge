
/*

*/
int abs(int v){
	int r;
	int mask = v >> sizeof(v) * CHAR_BIT - 1;
	return (v + mask) ^ mask;
}

int min(int x, int y){
	int r;
	r = y + ((x - y) & ((x - y) >> (sizeof(x) * CHAR_BIT - 1)));
	return r;
}

int max(int x, int y){
	int r;
	r = x - ((x - y) & ((x - y) >> (sizeof(x) * CHAR_BIT - 1)));
}

int ispower2(int v){
int f
f = v && !(v & (v - 1));
return f;
}

int bitcount(int v){
	int c;
	for (c = 0; v; c++){
  		v &= v - 1; // clear the least significant bit set
	}
	return c;
}
