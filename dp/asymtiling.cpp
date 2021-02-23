#include <stdio.h>
#include <string.h>
#define MOD 1000000007
using namespace std;

int dp[102];

int solve(int x, int n) {
	int& ret = dp[x];
	
	if (ret != -1)
		return ret;
	if (x + 1 >= n)
		return 1;

	ret = (solve(x + 1, n) + solve(x + 2, n)) % MOD;
	return ret;
}

int main() {
	int c;

	scanf(" %d", &c);
	while (c--) {
		int n;
		int answer;
		memset(dp, -1, sizeof(dp));

		scanf(" %d", &n);

		answer = solve(0, n);
		memset(dp, -1, sizeof(dp));
		answer = (answer - solve(0, n / 2 + (n % 2 == 0 ? 1 : 0)) + MOD) % MOD;
		printf("%d\n", answer);
	}
	return 0;
}
