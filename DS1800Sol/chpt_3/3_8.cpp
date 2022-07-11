#include <iostream>
#include "3_8.h"

int recEuclid(int num1, int num2)
{
	if (num2 == 0) {
		return num1; 
	}
	if (num1 < num2) {
		num1 += num2; 
		num2 = num1 - num2; 
		num1 -= num2; 
	}

	return recEuclid(num2, num1 % num2); 
}

int Euclid(int num1, int num2)
{
	if (num1 < num2) {
		num1 += num2;
		num2 = num1 - num2;
		num1 -= num2;
	}

	int cache = 0; 
	while (num2 != 0) {
		cache = num1; 
		num1 = num2; 
		num2 = cache % num2; 
	}

	return num1; 
}