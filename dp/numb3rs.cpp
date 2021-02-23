#include <stdio.h>
#include <string.h>

int a[51][51];
int deg[51];
double dp[51][102];

double solve(int x, int d, int n, int p) {
	double& ret = dp[x][d];

	if (ret >= 0.0)
		return ret;
	if (d == 0)
		return (x == p ? 1.0 : 0.0);

	ret = 0.0;
	for (int i = 0; i < n; i++)
		if (a[x][i])
			ret += solve(i, d - 1, n, p) / deg[i];
	return ret;
}

int main() {
	int c;

	scanf(" %d", &c);
	while (c--) {
		int n, d, p;
		int t, q;
		memset(deg, 0, sizeof(deg));
		memset(dp, -1, sizeof(dp));

		scanf(" %d %d %d", &n, &d, &p);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++){
				scanf(" %d", &a[i][j]);
				if (a[i][j])
					deg[i]++;
			}
		}

		scanf(" %d", &t);
		for (int i = 0; i < t; i++) {
			scanf(" %d", &q);
			printf("%.8f ", solve(q, d, n, p));
		}
		printf("\n");
	}
	return 0;
}
