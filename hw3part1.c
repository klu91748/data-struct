#include <stdio.h>
#include <stdlib.h>
const float PI = 3.14159;

float circle(float r);
float rectangle(float length, float width);
float triangle(float base, float height);

int main()
{

	printf("Geometry Calculator\n");
	printf("1. Calculate the Area of a Circle\n");
	printf("2. Calculate the Area of a Rectangle\n");
	printf("3. Calculate the Area of a Triangle\n");
	printf("4. Quit\n");

	printf("Enter your choice (1-4)\n");
	fflush(stdout); //use for i/o ECLIPSE ONLY
	int n = 0;
	scanf("%d", &n);

	if (n == 1)
	{
		printf("Input a radius\n");
		fflush(stdout);
		float radius;
		scanf("%f", &radius);

		while (radius < 0)
		{
			printf("Invalid. Enter a positive value.\n");
			fflush(stdout);
			scanf("%f", &radius);
		}

		float answer = circle(radius);
		printf("Area = %f", answer);
	}

	else if (n == 2)
	{
		printf("Input a length\n");
		fflush(stdout);
		float length;
		scanf("%f", &length);

		while (length < 0)
		{
			printf("Invalid. Enter a positive value.\n");
			fflush(stdout);
			scanf("%f", &length);
		}

		printf("Input a width\n");
		fflush(stdout);
		float width;
		scanf("%f", &width);

		while (width < 0)
		{
			printf("Invalid. Enter a positive value.\n");
			fflush(stdout);
			scanf("%f", &width);
		}

		float answer = rectangle(length, width);
		printf("Area = %f", answer);
	}

	else if (n == 3)
	{
		printf("Input a base\n");
		fflush(stdout);
		float base;
		scanf("%f", &base);

		while (base < 0)
		{
			printf("Invalid. Enter a positive value.\n");
			fflush(stdout);
			scanf("%f", &base);
		}

		printf("Input a height\n");
		fflush(stdout);
		float height;
		scanf("%f", &height);

		while (height < 0)
		{
			printf("Invalid. Enter a positive value.\n");
			fflush(stdout);
			scanf("%f", &height);
		}

		float answer = triangle(base, height);
		printf("Area = %f", answer);
	}

	else if (n == 4)
	{
		printf("Quiting...\n");
	}
	else
	{
		printf("Input invalid.");
	}


return 0;
}


float circle(float r)
{
	return (pow(r,2)*PI);
}

float rectangle(float length, float width)
{
	return length*width;
}

float triangle(float base, float height)
{
	return base*height*.5;
}
