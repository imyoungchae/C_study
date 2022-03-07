/*
2차원 배열로 5ⅹ5 틱택토 게임 구현
▪ 제시된 프로그램을 이용하여 5 x 5 칸이 있는 게임판을 만들고 배
열 위치 {(0, 0) ~ (4, 4)}를 지정하여 입력하면 동그라미 심벌(O)과
가위표 심벌(X)이 번갈아 가며 게임판에 나타나게 한다.
▪ 입력 값이 (-1, -1)이 입력 되면 종료되게 한다.
▪ system(“cls”) 명령문을 사용하여 게임판은 항상 화면의 위쪽에 나
타나게 한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#define CLS system("cls")

int Decision(char a[][5], int n);
void init_board(char board[][5]);
int get_player_move(int palyer, char board[][5]);
void disp_board(char board[][5]);
int k = 0;

int main()
{
	char board[5][5];
	int quit = 0;
	init_board(board); 

	
	while (true)
	{
		disp_board(board);  
		quit = get_player_move(0, board); 
		if (k == 25 || quit == 1) 
		{
			disp_board(board); 
			break;
		}
		disp_board(board); 
		quit = get_player_move(1, board); 
		if (quit == 1) 
		{
			break;
		}
	}

	
	int result = Decision(board, 5); 
	if (result == -1) {
		printf("\n게임 중단\n");
	}
	else if (result == 0) {
		printf("\n무승부\n");
	}
	else if (result == 1) {
		printf("\n'X' 승리\n");
	}
	else if (result == 2) {
		printf("\n'O' 승리\n");
	}

	return 0;
}
void init_board(char board[][5])
{
	int x, y;
	for (x = 0; x < 5; x++)
		for (y = 0; y < 5; y++) board[x][y] = ' ';
}

void disp_board(char board[5][5])
{
	int i;
	for (i = 0; i < 5; ++i)
	{
		printf("-----|-----|-----|-----|-----\n");
		printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
	}
	printf("-----|-----|-----|-----|-----\n");

}

int get_player_move(int player, char board[5][5])
{
	int x, y;
	int done = 0;
	k++;

	while (done != 1) {
		printf("(x, y) 좌표(종료-1, -1): ");
		scanf("%d %d", &x, &y);
		if (x == -1 && y == -1)
			return 1;
		if (board[x][y] == ' ')
			break;
		else
			printf("잘못된 위치입니다.\n");
	}

	
	board[x][y] = (player == 0) ? 'X' : 'O';

	return 0;
}
int Decision(char a[][5], int n)
{
	int i, j;
	int b[12] = { 0 }; 

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == 'X')
				a[i][j] = 0;
			else if (a[i][j] == 'O')
				a[i][j] = 1;
		}
	}

	
	for (i = 0; i < n; i++)
	{
		b[0] += a[i][0]; 
		b[1] += a[i][1]; 
		b[2] += a[i][2]; 
		b[3] += a[i][3]; 
		b[4] += a[i][4]; 
		b[5] += a[0][i]; 
		b[6] += a[1][i]; 
		b[7] += a[2][i]; 
		b[8] += a[3][i]; 
		b[9] += a[4][i]; 
		b[10] += a[i][i]; 
		b[11] += a[i][n - 1 - i]; 
	}

	
	for (j = 0; j < 12; j++)
	{
		
		if (b[j] == 0)
			return 1;
		
		else if (b[j] == 5)
			return 2;
	}
	if (k < 25)
		return -1;
	
	else if (k == 25)
		return 0;
	
}
