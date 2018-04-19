#include <stdio.h>

int* reverse();
void main()
{
	static int size = 3;
	int array[size];
	array[0] = 9;
	array[1] = 1;
	array[2] = 2;

	printf("This is before reversing the array:\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%i\t", array[i]);
	}
	printf("\n");

	int *p = reverse(array, size);



	printf("This is after reversing the array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%i\t", p[i]);
	}

}

int* reverse(int array[], int size)
{
	static int copy[3];
	int minus = size;

	printf("\n");
	printf("Reversing onto new array..\n");
	for (int i = 0; i < size; i++)
	{
		minus = minus - 1;
		copy[i] = array[minus];
	}

	return copy;
}
