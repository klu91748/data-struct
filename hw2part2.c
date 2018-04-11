void main()
{
	float oceanLevelRate = 1.5;
	int years = 5;
	float currentLevel = oceanLevelRate*years;

	printf("The ocean's level rose by %f millimeters in year 5!\n", currentLevel);
	years = 7-5;
	currentLevel = oceanLevelRate*years;

	printf("It is year 7. The ocean's level rose by %f millimeters since year 5!\n", currentLevel);
	years = 10-7;
	currentLevel = oceanLevelRate*years;

	printf("It is year 10.The ocean's level rose by %f millimeters since year 7!\n", currentLevel);

}
