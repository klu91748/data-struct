#include <stdio.h>

int main () {

	int shares = 1000;

	double price = 45.50;
	double finalPrice = shares*price;
	double commissionPrice = finalPrice*.02;
	double totalPaidPrice = finalPrice + commissionPrice;

	double soldPrice = 56.9;
	double finalSoldPrice = soldPrice*shares;
	double soldCommissionPrice = finalSoldPrice*.02;
	double totalSoldPrice = finalSoldPrice - soldCommissionPrice;

	double profit = totalSoldPrice - totalPaidPrice;

	printf("Joe paid $%.2f for each stocks.\n", totalPaidPrice);
	printf("Joe paid $%.2f for commission.\n", commissionPrice);
	printf("Joe sold his stock for $%.2f.\n", totalSoldPrice);
	printf("Joe had to pay $%.2f in commission after selling his stocks.\n", soldCommissionPrice);
	printf("Joe made $%.2f in profits.\n", profit);

	return 0;
}
