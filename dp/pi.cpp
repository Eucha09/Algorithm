#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 987654321
using namespace std;

char arr[10004];
int dp[10004];

int dif(int s, int e) {
	int ret = 1;
	int c;

	for (int i = s; i < e - 1 && ret == 1; i++) {
		if (arr[i] != arr[i + 1])
			ret++;
	}
	c = arr[s] - arr[s + 1];
	for (int i = s + 1; i < e - 1 && ret == 2; i++) {
		if (c * c != 1 || arr[i] - arr[i + 1] != c)
			ret += 2;
	}
	for (int i = s + 2; i < e && ret == 4; i++) {
		if (arr[i] != arr[i - 2])
			ret++;
	}
	for (int i = s + 1; i < e - 1 && ret == 5; i++) {
		if (arr[i] - arr[i + 1] != c)
			ret += 5;
	}
	return ret;
}

int solve(int s, int n) {
	int& ret = dp[s];
	
	if (ret != -1)
		return ret;
	if (s == n)
		return 0;

	ret = INF;
	for (int i = 3; i <= 5; i++) {
		if (s + i <= n)
			ret = min(ret, dif(s, s + i) + solve(s + i, n));
	}
	return ret;
}

int main() {
	int c;

	scanf(" %d", &c);
	while (c--) {
		int n;
		memset(dp, -1, sizeof(dp));

		scanf(" %s", arr);
		n = strlen(arr);
		for (int i = 0; i < n; i++)
			arr[i] -= '0';

		printf("%d\n", solve(0, n));
	}
	return 0;
}
