#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int ranking[502];
vector<pair<int, int>> change;
int graph[502][502];
int visited[502];
int finished[502];
int isCycle;
vector<int> order;

void dfs(int cur, int n)
{
	visited[cur] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (graph[cur][i] == 1)
		{
			if (visited[i] == 0)
				dfs(i, n);
			else if (finished[i] == 0)
				isCycle = 1;
		}
	}

	finished[cur] = 1;
	order.push_back(cur);
}

int main()
{
	int t;

	scanf(" %d", &t);
	while (t--)
	{
		int n, m;
		change.clear();
		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		isCycle = 0;
		order.clear();

		scanf(" %d", &n);
		for (int i = 1; i <= n; i++)
			scanf(" %d", ranking + i);
		scanf(" %d", &m);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf(" %d %d", &a, &b);
			change.push_back(pair<int, int>(a, b));
		}

		// 그래프를 만든다
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				graph[ranking[i]][ranking[j]] = 1;

		// 간선 방향 뒤집기
		for (int i = 0; i < m; i++)
		{
			if (graph[change[i].first][change[i].second] == 0)
			{
				graph[change[i].first][change[i].second] = 1;
				graph[change[i].second][change[i].first] = 0;
			}
			else
			{
				graph[change[i].first][change[i].second] = 0;
				graph[change[i].second][change[i].first] = 1;
			}
		}

		// 위상정렬 시작
		for (int i = 1; i <= n; i++)
			if(visited[i] == 0)
				dfs(i, n);

		if (isCycle)
			printf("IMPOSSIBLE\n");
		else
		{
			reverse(order.begin(), order.end());
			for (int i = 0; i < order.size(); i++)
				printf("%d ", order[i]);
			printf("\n");
		}
	}
	return 0;
}
