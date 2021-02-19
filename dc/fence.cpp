#include <stdio.h>
#include <algorithm>
using namespace std;

int fence[20005];

int solve(int l, int r)
{
	int ret;
	int mid, h, w;
	int a, b;
	
	if(l == r)
		return fence[l];
	
	mid = (l + r) / 2;
	a = b = mid;
	h = fence[mid];
	w = 1;
	ret = h;
	
	while(l < a || b < r)
	{
		if(l < a && (b == r || fence[a - 1] >= fence[b + 1]))
		{
			h = min(h, fence[a - 1]);
			a--;
			w++;
		}
		else if(b < r && (l == a || fence[a - 1] <= fence[b + 1]))
		{
			h = min(h, fence[b + 1]);
			b++;
			w++;
		}
		ret = max(ret, h * w);
	}
	ret = max(ret, solve(l, mid));
	ret = max(ret, solve(mid + 1, r));
	return ret;
}

int main()
{
	int c;
	
	scanf(" %d", &c);
	while(c--)
	{
		int n;
		
		scanf(" %d", &n);
		for(int i = 0; i < n; i++)
			scanf(" %d", &fence[i]);
			
		printf("%d\n", solve(0, n - 1));
	}
	return 0;
}
