#include <stdio.h>

char array[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void printArray();

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
			scanf("%i %i",&r, &c);
			array[r][c] = 'X';

			playerOne = 0;
			playerTwo = 1;

		}
		else if (playerTwo)
		{
			printf("Player 2, please enter [row][column]");
			fflush(stdout);

			int r, c;
			scanf("%i %i",&r, &c);
			array[r][c] = 'O';

			playerOne = 1;
			playerTwo = 0;

		}
		printArray();
	}
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
