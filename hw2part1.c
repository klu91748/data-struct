void main() {
	float tax = .0675;
	float meal = 88.67;
	float tip = .2;
	float mealWithTax = meal + (meal * tax);
	float total = mealWithTax + (mealWithTax * tip);

	printf("Meal: %.2f\n", meal);
	printf("Tax: %.4f\n", tax);
	printf("Tip: %.2f\n", tip);
	printf("Total: %.2f\n", total);
}
