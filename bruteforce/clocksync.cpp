#include <stdio.h>
#include <algorithm>
#define INF 987654321
using namespace std;

int clocks[16];
int switchs[10][6] = {
	{3, 0, 1, 2},
	{4, 3, 7, 9, 11},
	{4, 4, 10, 14, 15},
	{5, 0, 4, 5, 6, 7},
	{5, 6, 7, 8, 10, 12},
	{4, 0, 2, 14, 15},
	{3, 3, 14, 15},
	{5, 4, 5, 7, 14, 15},
	{5, 1, 2, 3, 4, 5},
	{5, 3, 4, 5, 9, 13}
};

int solve(int n, int cnt) // n : 스위치 번호, cnt : 지금까지 스위치 누른 총 횟수
{
	int ret = INF;
	
	if(n == 10) // 모든 스위치를 확인했다면
	{
		bool bo = 1;
		for(int i = 0; i < 16 && bo; i++) // 모든 시계가 12시인지
			if(clocks[i] != 12)
				bo = 0;
		return bo ? cnt : ret;
	}
	
	// 스위치마다 안누르거나, 1번누르거나, 2번누르거나, 3누르거나 4가지 경우밖에 없다
	for(int i = 0; i < 4; i++) // 4가지 경우 다 해보기
	{
		ret = min(ret, solve(n + 1, cnt + i));
		for(int j = 1; j <= switchs[n][0]; j++)
		{
			clocks[switchs[n][j]] += 3;
			if(clocks[switchs[n][j]] > 12)
				clocks[switchs[n][j]] -= 12;
		}
	}
	return ret;
}

int main()
{
	int c;
	
	scanf(" %d", &c);
	while(c--)
	{
		int ret;
		
		for(int i = 0; i < 16; i++)
			scanf(" %d", &clocks[i]);
		
		ret = solve(0, 0);
		printf("%d\n", ret < INF ? ret : -1);
	}
	return 0;
}
