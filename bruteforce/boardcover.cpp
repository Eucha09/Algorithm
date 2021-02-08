#include <stdio.h>
#include <string.h>

int board[25][25]; // 게임판 #(검은칸)은 0, .(흰칸)은 1
int dy[4][2] = { {1, 1}, {1, 1}, {0, 1}, {0, 1} };
int dx[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {1, 1} };

int solve(int h, int w)
{
	int ret = 0;
	int y = 0, x = 0; // 흰칸 좌표
	
	for(int i = 1; i <= h; i++) // 흰칸을 찾는다
	{
		for(int j = 1; j <= w; j++)
		{
			if(board[i][j])
			{
				y = i;
				x = j;
				break;
			}
		}
		if(y != 0) // 흰칸 찾았으면 break
			break;
	}
	
	if(y == 0) // 흰칸이 없다면 게임판을 다 덮었다는 의미이므로 return
		return 1;
	
	// L자 모양 블록을 놓는 방법
	//  *   *    **   **
	// **   **   *     *
	for(int i = 0; i < 4; i++) // 4가지 방법 다 시도해보기
	{
		int ny1 = y + dy[i][0];
		int nx1 = x + dx[i][0];
		int ny2 = y + dy[i][1];
		int nx2 = x + dx[i][1];
		if(board[ny1][nx1] && board[ny2][nx2]) // 블록을 놓을 수 있는지
		{
			board[y][x] = 0;
			board[ny1][nx1] = 0;
			board[ny2][nx2] = 0;
			ret += solve(h, w);
			board[y][x] = 1;
			board[ny1][nx1] = 1;
			board[ny2][nx2] = 1;
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
		int h, w;
		memset(board, 0, sizeof(board));
		
		scanf(" %d %d", &h, &w);
		for(int i = 1; i <= h; i++)
		{
			for(int j = 1; j <= w; j++)
			{
				char a;
				scanf(" %c", &a);
				board[i][j] = (a == '#') ? 0 : 1;
			}
		}
		
		printf("%d\n", solve(h, w));
	}
	return 0;
}
