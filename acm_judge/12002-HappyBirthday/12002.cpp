#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, tn;
int s[512], t[512];
int map[1024];

int LIS(int *a, int num, int threshold)	/* finding the length of LIS of array 'a' using elements < threshold */
{
	if (!num)
		return (0);
	vector<int> v;
	for (int i = 0; i < num; ++i)
	{
		int p = a[i];
		if (p >= threshold)
			continue;
		if (!v.size())
		{
			v.push_back(p);
			continue;
		}
		if (p >= v.back())
			v.push_back(p);
		else
			*upper_bound(v.begin(), v.end(), p) = p;
	}
	return v.size();
}

bool myCompare(int a, int b)
{
	return (a > b);
}

int LDS(int *a, int num, int threshold)	/* finding the length of LDS of array 'a' using elements > threshold */
{
	if (!num)
		return (0);
	vector<int> v;
	for (int i = 0; i < num; ++i)
	{
		int p = a[i];
		if (p <= threshold)
			continue;
		if (!v.size())
		{
			v.push_back(p);
			continue;
		}
		if (p <= v.back())
			v.push_back(p);
		else
			*upper_bound(v.begin(), v.end(), p, myCompare) = p;
	}
	return v.size();
}

void dp()
{
	int i, l1, l2, pmin, cnt, ans = 0, r1, r2;
	for (i = 0; i < n; ++i)
	{
		l1 = LIS(s, i, s[i]+1);
		l2 = LDS(s, i, s[i]);
#if 0
		printf("i = %d, l1 = %d, l2 = %d\n", i, l1, l2);
#endif
		r1 = l1 + l2 + 1;
		l1 = LIS(s, i, s[i]);
		l2 = LDS(s, i, s[i]-1);
		r2 = l1 + l2 + 1;
#if 0
		printf("i = %d, l1 = %d, l2 = %d\n", i, l1, l2);
#endif
		ans = max(ans, max(r1, r2));
	}
	cout << ans << endl;
}

int compare(const void *a, const void *b)
{
	int c, d;
	c = *(int *)(a);
	d = *(int *)(b);
	return (c - d);
}

inline void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void refine()
{
	tn = 0;
	qsort((void *)t, n, sizeof(int), compare);
	map[t[0]] = tn++;
	for (int i = 1; i < n; ++i)
		if (t[i] != t[i-1])
			map[t[i]] = tn++;
	for (int i = 0; i < n; ++i)
		s[i] = map[s[i]];
	for (int i = 0, j = n-1; i < j; ++i, --j)
		swap(s[i], s[j]);
}

int main()
{
	while (cin >> n && n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
			t[i] = s[i];
		}
		refine();
		dp();
	}
	return (0);
}
