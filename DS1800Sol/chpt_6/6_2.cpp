#include <iostream>
#include "6_2.h"

int calculate(BiTree expr)
{
	if (expr->data >= '0' && expr->data <= '9') {
		return expr->data - '0'; 
	}

	int item = calculate(expr->left); 
	int jtem = calculate(expr->right); 
	int result = 0; 

	switch (expr->data) {
	case '+' :
		result = item + jtem;
		break; 
	case '-' :
		result = item - jtem;
		break;
	case '*' :
		result = item * jtem;
		break;
	case '/' :
		result = item / jtem;
		break;
	}

	return result; 
}