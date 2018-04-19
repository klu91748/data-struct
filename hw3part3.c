#include <stdio.h>

char array[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};

void printArray();
int winCondition();

void main()
{
	printArray();

	int playerOne = 1;
	int playerTwo = 1;
	int j = 1;

	while(j > 0)
	{
		if (playerOne)
		{
			printf("Player 1, please enter [row][column]");
			fflush(stdout);

			int r, c;
			while (array[r-1][c-1] != '*')
			{
				scanf("%i %i",&r, &c);
			}
			array[r-1][c-1] = 'X';

			playerOne = 0;
			playerTwo = 1;

		}
		else if (playerTwo)
		{
			printf("Player 2, please enter [row][column]");
			fflush(stdout);

			int r, c;
			while (array[r-1][c-1] != '*')
			{
				scanf("%i %i",&r, &c);
			}
			array[r-1][c-1] = 'O';

			playerOne = 1;
			playerTwo = 0;

		}
		printArray();
		j = winCondition();
	}
}


int winCondition()
{
	int j = 1;

	if (array[0][0] == 'X' && array[0][1] == 'X' && array[0][2] == 'X' ||
		array[1][0] == 'X' && array[1][1] == 'X' && array[1][2] == 'X' ||
		array[2][0] == 'X' && array[2][1] == 'X' && array[2][2] == 'X' ||
		array[0][0] == 'X' && array[1][0] == 'X' && array[2][0] == 'X' ||
		array[0][1] == 'X' && array[1][1] == 'X' && array[2][1] == 'X' ||
		array[0][2] == 'X' && array[1][2] == 'X' && array[2][2] == 'X' ||
		array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X' ||
		array[0][2] == 'X' && array[1][1] == 'X' && array[2][0] == 'X')
	{
		printf("Player 1 wins.\n");
		j = 0;
	}

	if (array[0][0] == 'O' && array[0][1] == 'O' && array[0][2] == 'O' ||
		array[1][0] == 'O' && array[1][1] == 'O' && array[1][2] == 'O' ||
		array[2][0] == 'O' && array[2][1] == 'O' && array[2][2] == 'O' ||
		array[0][0] == 'O' && array[1][0] == 'O' && array[2][0] == 'O' ||
		array[0][1] == 'O' && array[1][1] == 'O' && array[2][1] == 'O' ||
		array[0][2] == 'O' && array[1][2] == 'O' && array[2][2] == 'O' ||
		array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == 'O' ||
		array[0][2] == 'O' && array[1][1] == 'O' && array[2][0] == 'O')
	{
		printf("Player 2 wins.\n");
		j = 0;
	}
	return j;
}

void printArray()
{
	for (int rows = 0; rows < 3; rows++)
	{
		for(int columns = 0 ; columns < 3 ; columns++ )
		{
			printf("%c", array[rows][columns]);
		}
		printf("\n");
	}
}
