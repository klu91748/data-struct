#include <stdio.h>
float calculate(float p, float b, float d, float display);

void main()
{
	printf("Enter size of population\n");
    fflush(stdout);//use for i/o ECLIPSE ONLY
    float population;
    scanf("%f", &population);
    while (population < 2)
    {
    	printf("Population must not be less than two");
    	fflush(stdout);//use for i/o ECLIPSE ONLY
    	scanf("%f", &population);
    }


	printf("Enter annual birth rate\n");
    fflush(stdout);//use for i/o ECLIPSE ONLY
    float birth;
    scanf("%f", &birth);
    while (birth < 0)
    {
    	printf("Invalid. Cannot be a negative number");
    	fflush(stdout);//use for i/o ECLIPSE ONLY
    	scanf("%f", &birth);
    }

	printf("Enter annual death rate\n");
    fflush(stdout);//use for i/o ECLIPSE ONLY
    float death;
    scanf("%f", &death);
    while (death < 0)
    {
    	printf("Invalid. Cannot be a negative number");
    	fflush(stdout);//use for i/o ECLIPSE ONLY
    	scanf("%f", &death);
    }

	printf("Number of years to display\n");
    fflush(stdout);//use for i/o ECLIPSE ONLY
    float display;
    scanf("%f", &display);
    while (display < 1)
    {
    	printf("Invalid. Cannot be less than one.");
    	fflush(stdout);//use for i/o ECLIPSE ONLY
    	scanf("%f", &display);
    }

    float answer = calculate(population, birth, death, display);
    printf ("Population in %.0f years will be %.0f", display, answer);
}

float calculate(float p, float b, float d, float display)
{
	float answer = p;
	for (int i = 0; i < display; i++)
	{
		answer = answer + (p + p*b - p*d);
	}
	return answer;
}

