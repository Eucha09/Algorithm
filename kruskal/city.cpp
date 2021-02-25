#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
	int a, b, cost;
	bool operator<(const edge& b)const
	{
		return cost < b.cost;
	}
};

vector<edge> edges;

// union-find
int parent[100005];

int find_parent(int x)
{
	if (parent[x] != x)
		parent[x] = find_parent(parent[x]);
	return parent[x];
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	int n, m;
	int ret = 0;
	int maxCost = 0;

	scanf(" %d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf(" %d %d %d", &a, &b, &c);
		edges.push_back({ a, b, c });
	}

	for (int i = 1; i <= n; i++)
		parent[i] = i;
	sort(edges.begin(), edges.end());
	
	for (int i = 0; i < edges.size(); i++)
	{
		edge cur = edges[i];
		if (find_parent(cur.a) != find_parent(cur.b))
		{
			union_parent(cur.a, cur.b);
			ret += cur.cost;
			maxCost = cur.cost;
		}
	}

	ret -= maxCost;
	printf("%d\n", ret);
	return 0;
}
