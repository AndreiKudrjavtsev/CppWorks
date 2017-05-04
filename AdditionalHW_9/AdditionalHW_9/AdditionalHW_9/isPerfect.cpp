bool isPerfect(int number) {
	int sum = 1;
	for (int i = 2; i <= number / 2; i++) {
		if (number % i == 0)
			sum += i;
	}
	return number == sum ? true : false;
}