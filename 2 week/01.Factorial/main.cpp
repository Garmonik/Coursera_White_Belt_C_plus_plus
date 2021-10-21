int Factorial(int num){
	if (num <= 1)
		return 1;
	else{
		return num * Factorial(num - 1);
	}
}
