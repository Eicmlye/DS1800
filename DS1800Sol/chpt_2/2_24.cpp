/*
	定义两个指针mov和chg, 初始均指向A的第一个元素. mov和chg同时沿A遍历线性表, 当mov指向的值不为item时, 将两个指针所指的值交换后继续遍历; 当mov指向的值为item时, mov沿A向后移动而chg不动. 当mov完成遍历时算法结束. 
*/

#include <iostream>
#include "2_24.h"

void delItem(int* arr, size_t& n, int item)
{
	size_t mov = 0; 
	size_t chg = 0; 
	size_t len = n; 

	while (mov < len) {
		if (arr[mov] != item) {
			if (mov != chg) {
				arr[mov] += arr[chg];
				arr[chg] = arr[mov] - arr[chg];
				arr[mov] -= arr[chg];
			}
			++chg; 
		}
		else {
			--n; 
		}

		++mov; 
	}

	return; 
}