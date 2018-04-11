#include <stdio.h>

int main () {

	for (int x = 1; x <= 10; x++)
	{
		for(int y = 1; y <= x; y++)
		{
			printf("+");
		}
		printf("\n");
	}

	for (int x = 10; x > 0; x--)
	{
		for (int y = 10; y >= x; y--)
		{
			printf("+");
		}
		printf("\n");
	}

	return 0;
}
