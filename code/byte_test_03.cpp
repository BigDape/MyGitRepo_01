#include <iostream>
#define maxn 3010
#include <algorithm>
#define ll long long
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int a[maxn], b[maxn];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}
	sort(a, a + n);
	ll sum = 0;
	for (int i = 0; i < m; ++i)
	{
		int p = upper_bound(a,a+n,b[i])-a;
		sum = sum + b[i] - a[p - 1];
	}
	printf("%lld\n",sum);
	return 0;
}