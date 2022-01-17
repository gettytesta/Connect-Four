#include <stdlib.h>
#include <stdio.h>

void printBoard(int board[6][7]);
int checkWin(int board[6][7], bool winState);

int main(int argc, char* argv)
{
	int winnerCheck = 0;
	static int cfBoard[6][7];

	int x;
	bool check;

	//Int to alternate between players
	//Positive 1: Player 1
	//Negative 1: Player 2
	int playerTurn = -1;

	printBoard(cfBoard);

	while (winnerCheck == 0)
	{
		//Alternates player
		playerTurn = -playerTurn;

		//Lets player choose where to place token
		printf("Player %i's Turn\n", (playerTurn > 0) ? 1 : 2);
		do
		{
			printf("Choose a Column: ");
			//Screen buffer to look nice:)
			for (int i = 0; i < 21; i++)
			{
				printf("\n");
			}
			scanf_s("%i", &x);

			if (x > 7 || x < 1)
			{
				check = true;
				printBoard(cfBoard);
				printf("Invalid Column!\n");
			}
			else if (cfBoard[0][x-1] != 0)
			{
				check = true;
				printBoard(cfBoard);
				printf("Column is already full!\n");	
			}
			else
			{
				check = false;
			}
		} while (check);

		//Places the 'chip' on the board
		for (int i = 5; i >= 0; i--)
		{
			if (cfBoard[i][x-1] == 0)
			{
				cfBoard[i][x-1] = playerTurn;
				break;
			}
		}

		//Checks for a win and prints the board
		winnerCheck = checkWin(cfBoard, false);
		printBoard(cfBoard);
	}

	//Screen buffer pt. 2 
	for (int i = 0; i < 23; i++)
	{
		printf("\n");
	}

	checkWin(cfBoard, true);
	printBoard(cfBoard);
	printf("Player %i Wins!\n\n", (playerTurn > 0) ? 1 : 2);
}

int checkWin(int board[6][7], bool winState)
{
	int RorB;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			//Checks for four in a row on the x axis
			if (board[i][j] != 0)
			{
				RorB = board[i][j];
				int c = 1;
				while (board[i][j + c] == RorB)
				{
					++c;
					if (c == 4)
					{
						if (winState == true)
						{
							for (c-1; c >= 0; c--)
							{
								board[i][j + c] = 2 * RorB;
							}
						}
						return RorB;
					}
				}
			}

			//Checks for four in a row on the y axis
			if (board[i][j] != 0)
			{
				RorB = board[i][j];
				int c = 1;
				while (board[i + c][j] == RorB)
				{
					++c;
					if (c == 4)
					{
						if (winState == true)
						{
							for (c-1; c >= 0; c--)
							{
								board[i + c][j] = 2 * RorB;
							}
						}
						return RorB;
					}
				}
			}
		}
	}

	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//Checks for four in a row on the diagonal up
			if (board[i][j] != 0)
			{
				RorB = board[i][j];
				int c = 1;
				while (board[i - c][j + c] == RorB)
				{
					++c;
					if (c == 4)
					{
						if (winState == true)
						{
							for (c-1; c >= 0; c--)
							{
								board[i - c][j + c] = 2 * RorB;
							}
						}
						return RorB;
					}
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//Checks for four in a row on the diagonal down
			if (board[i][j] != 0)
			{
				RorB = board[i][j];
				int c = 1;
				while (board[i + c][j + c] == RorB)
				{
					++c;
					if (c == 4)
					{
						if (winState == true)
						{
							for (c-1; c >= 0; c--)
							{
								board[i + c][j + c] = 2 * RorB;
							}
						}
						return RorB;
					}
				}
			}
		}
	}
	
	return 0;
}

void printBoard(int board[6][7])
{
	for (int i = 0; i < 6; i++)
	{
		printf("|");
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == 1)
			{
				printf("X|");
			}
			else if (board[i][j] == -1)
			{
				printf("O|");
			}
			else if (board[i][j] == 2)
			{
				printf("*|");
			}
			else if (board[i][j] == -2)
			{
				printf(".|");
			}
			else
			{
				printf("_|");
			}
		}
		printf("\n");
	}
	printf("\n");
}