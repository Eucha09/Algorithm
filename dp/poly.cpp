#include <stdio.h>
#include <string.h>
#define MOD 10000000
using namespace std;

int dp[102][102];

int solve(int x, int n) {
	int& ret = dp[x][n];

	if (ret != -1)
		return ret;
	if (x == n)
		return 1;

	ret = 0;
	for (int i = 1; i <= (n - x); i++) {
		ret = (ret + solve(i, n - x) * (x + i - 1)) % MOD;
	}
	return ret;
}

int main() {
	int c;

	scanf(" %d", &c);
	while (c--) {
		int n;
		int answer = 0;
		memset(dp, -1, sizeof(dp));

		scanf(" %d", &n);

		for (int i = 1; i <= n; i++)
			answer = (answer + solve(i, n)) % MOD;

		printf("%d\n", answer);
	}
	return 0;
}
