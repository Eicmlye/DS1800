/*
	(1) ������������index��jndex����ʼֵ��Ϊ0���ֱ�ͬʱ����A��B: ��A[index] >= B[jndex]ʱ��jndex��B�ƶ�һ��Ԫ��; ��֮��index��A�ƶ�һ��Ԫ�ء��������ƶ��ܴ���ΪLʱ, �ƶ�ǰ��Ԫ�ؼ�Ϊ��λ����
	
	(3) �㷨��ʱ�临�Ӷ�ΪO(L/2) = O(L), �ռ临�Ӷ�ΪO(1); 
*/

#include <iostream>
#include "2_3.h"

int findMid(int* A, int* B, size_t L)
{
	size_t index = 0; 
	size_t jndex = 0; 
	int result = 0; 

	while (index + jndex < L) {
		if (A[index] >= B[jndex]) {
			result = B[jndex];
			++jndex; 
		}
		else {
			result = A[index];
			++index; 
		}
	}

	return result; 
}