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

vector<pair<int, int>> vx;
vector<pair<int, int>> vy;
vector<pair<int, int>> vz;
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
	int n;
	int ret = 0;

	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		scanf(" %d %d %d", &x, &y, &z);
		vx.push_back(pair<int, int>(x, i));
		vy.push_back(pair<int, int>(y, i));
		vz.push_back(pair<int, int>(z, i));
	}

	for (int i = 0; i < n; i++)
		parent[i] = i;
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	sort(vz.begin(), vz.end());
  // 간선 만들기
	for (int i = 0; i < n - 1; i++)
		edges.push_back({ vx[i].second, vx[i + 1].second, vx[i + 1].first - vx[i].first });
	for (int i = 0; i < n - 1; i++)
		edges.push_back({ vy[i].second, vy[i + 1].second, vy[i + 1].first - vy[i].first });
	for (int i = 0; i < n - 1; i++)
		edges.push_back({ vz[i].second, vz[i + 1].second, vz[i + 1].first - vz[i].first });

	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		edge cur = edges[i];
		if (find_parent(cur.a) != find_parent(cur.b))
		{
			union_parent(cur.a, cur.b);
			ret += cur.cost;
		}
	}

	printf("%d\n", ret);
	return 0;
}
