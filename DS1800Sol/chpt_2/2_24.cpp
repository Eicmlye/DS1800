/*
	��������ָ��mov��chg, ��ʼ��ָ��A�ĵ�һ��Ԫ��. mov��chgͬʱ��A�������Ա�, ��movָ���ֵ��Ϊitemʱ, ������ָ����ָ��ֵ�������������; ��movָ���ֵΪitemʱ, mov��A����ƶ���chg����. ��mov��ɱ���ʱ�㷨����. 
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