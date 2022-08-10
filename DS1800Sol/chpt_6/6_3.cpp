/*
	Ϊ�����ŷ���, ��ȡӦ�������, ��ʵ�ʼ������������;  
	�������Ӧ���ȼ����ڵ�Ϊ�������ֵ, ��ȷ���Ƿ�ΪҶ�ڵ�; 

	Ϊ������ڵ㲻��Ҫ�����ŵ�����, �㷨�Ļ����߼�Ϊ: ��ÿ�������㴦������������������, �����Ǵ���������㱾�������; 

	����������������ȼ������ڸ��������, ������������Ҫ������; 
	����ʵ�ʼ����Ǻ��������, ��Ҷ��������������ȼ����ڸ������������������ʱ, �Ų��ü�����; ע���������ȼ����δ��������ȥ, �ǿ��ǵ�������ʱ��ŵ�����; 
	ͬ���ȼ�ʱ, �����Ϊ������ʱ, ��Ҷ���������������; 

	����������������ͬһ����� showExpr ���� needRight ƥ��, ƥ��ȷ�ϼ��ɵ� PRINTLPAR ��; 
*/

#include <iostream>
#include "6_3.h"

#define PRINTLPAR \
	do {\
		std::cout << '('; \
		needRight = true; \
	} while (0)
#define PRINTRPAR std::cout << ')'
#define PRINTDATA std::cout << expr->data
#define PRINTOP std::cout << ' ' << expr->data << ' '

static int op2prio(const char op, bool isSigned = false)
{
	switch (op) {
	case '+':
		return 1;
		break;
	case '-':
		return isSigned ? -1 : 1; 
		break; 
	case '*':
		return 2;
		break;
	case '/':
		return isSigned ? -2 : 2; 
		break; 
	default: // number; 
		return INT_MAX;
	}
}

void showExpr(BiTree expr)
{
	if (expr->left == nullptr) { // since all operators are binary, expr->right will also be nullptr; 
		PRINTDATA; 
	}
	else { // The binarity indicates that expr->right will also be non-nullptr; 
		bool needRight = false;
		if (op2prio(expr->data) > op2prio(expr->left->data)) {
			PRINTLPAR;
		}
		showExpr(expr->left);
		if (needRight) {
			PRINTRPAR;
		}

		PRINTOP;
		
		needRight = false; 
		if (op2prio(expr->data) > op2prio(expr->right->data)) {
			PRINTLPAR; 
		}
		else if (op2prio(expr->data) == op2prio(expr->right->data)) { // numbers have highest priority, so here expr->data cannot be numbers; 
			if (op2prio(expr->data, true) < 0) { // root op is an inv op; 
				PRINTLPAR;
			}
		}
		showExpr(expr->right);
		if (needRight) {
			PRINTRPAR;
		}
	}

	return; 
}