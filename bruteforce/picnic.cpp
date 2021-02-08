#include <stdio.h>
#include <string.h>

int mate[15][15]; // 서로 친구 인지 아닌지 1, 0
int student[15]; // 학생 선택 했는지 안했는지 1, 0

int solve(int sel, int n) // sel : 현재 고른 학생 수, n : 전체 학생 수
{
	int ret = 0;
	int a; // 짝을 찾을 학생
	
	if(n == sel) // 현재 고른 학생 수와 n이 같으면 하나의 경우를 찾았으니 return 1
		return 1;
	
	for(int i = 0; i < n; i++) // 짝을 찾을 학생 고르기 a
	{
		if(student[i] == 0) // 아직 선택 안된 학생이 맞는지
		{
			a = i;
			student[i] = 1;
			break;
		}
	}
	for(int i = 0; i < n; i++) // 선택 안된 학생중 a 학생 친구 찾기
	{
		if(student[i] == 0 && mate[a][i] == 1)
		{
			student[i] = 1;
			ret += solve(sel + 2, n); // 남은 학생수 중에 짝 고르기
			student[i] = 0; 
		}
	}
	student[a] = 0;
	return ret;
}

int main()
{
	int c;
	
	scanf("%d", &c);
	while(c--)
	{
		int n, m;
		memset(mate, 0, sizeof(mate));
		memset(student, 0, sizeof(student));
		
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			mate[a][b] = 1; // 서로 친구인 것을 표시
			mate[b][a] = 1; // 서로 친구인 것을 표시
		}
		
		printf("%d\n", solve(0, n));
	}
	return 0;
}
