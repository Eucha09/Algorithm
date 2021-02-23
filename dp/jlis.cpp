#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[105];
ll b[105];
int dp[105][105];

int solve(int s1, int s2, int n, int m) {
	int& ret = dp[s1][s2];
	ll p;

	if (ret != -1)
		return ret;

	p = max(a[s1], b[s2]);

	ret = 2;
	for (int i = s1 + 1; i <= n; i++) {
		if (p < a[i])
			ret = max(ret, 1 + solve(i, s2, n, m));
	}
	for (int i = s2 + 1; i <= m; i++) {
		if (p < b[i])
			ret = max(ret, 1 + solve(s1, i, n, m));
	}
	return ret;
}

int main() {
	int c;

	scanf(" %d", &c);
	while (c--) {
		int n, m;
		memset(dp, -1, sizeof(dp));
		a[0] = -10000000000;
		b[0] = -10000000000;

		scanf(" %d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf(" %lld", a + i);
		for (int i = 1; i <= m; i++)
			scanf(" %lld", b + i);

		printf("%d\n", solve(0, 0, n, m) - 2);
	}
	return 0;
}
