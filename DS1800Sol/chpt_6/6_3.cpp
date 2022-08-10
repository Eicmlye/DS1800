/*
	为加括号方便, 读取应中序遍历, 但实际计算必须后序遍历;  
	中序遍历应当先检查根节点为算符还是值, 以确定是否为叶节点; 

	为处理根节点不需要加括号的问题, 算法的基本逻辑为: 在每个算符结点处理其左、右子树的括号, 而不是处理该算符结点本身的括号; 

	若左子树根算符优先级不低于该树根算符, 则左子树不需要加括号; 
	由于实际计算是后序遍历的, 非叶右子树根算符优先级高于该树根算符且满足结合律时, 才不用加括号; 注意这里优先级相等未被包含进去, 是考虑到加括号时变号的问题; 
	同优先级时, 根算符为逆运算时, 非叶右子树必须加括号; 

	右括号与左括号在同一算符的 showExpr 中用 needRight 匹配, 匹配确认集成到 PRINTLPAR 中; 
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