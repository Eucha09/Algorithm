#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 987654321
using namespace std;

int arr[102];
int pSum[102];
int pSqSum[102];
int dp[102][11];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		pSum[i] = pSum[i - 1] + arr[i];
		pSqSum[i] = pSqSum[i - 1] + arr[i] * arr[i];
	}
}

int solve(int a, int n, int s) {
	int& ret = dp[a][s];
	int sum;
	int sqSum;
	int aver;
	int err;

	if (ret != -1)
		return ret;
	if (s == 1) {
		sum = pSum[n] - pSum[a - 1];
		sqSum = pSqSum[n] - pSqSum[a - 1];
		aver = (int)((double)sum / (n - a + 1) + 0.5);
		err = sqSum - 2 * aver * sum + aver * aver * (n - a + 1);
		return err;
	}
	if (n - a == 0)
		return 0;

	ret = INF;
	for (int i = 0; i < n; i++) {
		if (a + i <= n) {
			sum = pSum[a + i] - pSum[a - 1];
			sqSum = pSqSum[a + i] - pSqSum[a - 1];
			aver = (int)((double)sum / (i + 1) + 0.5);
			err = sqSum - 2 * aver * sum + aver * aver * (i + 1);
			ret = min(ret, err + solve(a + i + 1, n, s - 1));
		}
	}
	return ret;
}

int main() {
	int c;

	scanf(" %d", &c);
	while (c--) {
		int n, s;
		memset(dp, -1, sizeof(dp));
		
		scanf(" %d %d", &n, &s);
		for (int i = 1; i <= n; i++)
			scanf(" %d", arr + i);

		sort(arr + 1, arr + n + 1);
		init(n);
		printf("%d\n", solve(1, n, s));
	}
	return 0;
}
