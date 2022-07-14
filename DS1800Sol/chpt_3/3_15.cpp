/*
	S1 ��Ϊ�������, S2 ��Ϊ������������ S1 Ϊ��ʱ, ���ֱ����ջ S1 ����; �� S1 �ǿ�, �Ƚ� S1 ��Ԫ�س�ջ��������ջ�� S2, �ٽ�Ҫ��ӵ�Ԫ����ջ S1���� S2 �ǿ�ʱ, ����ֱ�ӳ�ջ S2 ����; �� S2 Ϊ��, �Ƚ� S1 �е�Ԫ�س�ջ��������ջ�� S2, �ٽ� S2 ��ջһ�μ���. ��֤����Ϊ�ռ���֤����ջ��Ϊ��. 
*/

#include <iostream>
#include "3_15.h"

void enqueue(DStkQue& que, const int x)
{
	if (que.stkIn_->top_ != que.stkIn_->size_) { // stkIn not full; 
		que.stkIn_->PUSH(x); 
	}
	else if (que.stkOut_->Sempty()) { // stkIn full, stkOut empty; 
		int cache = 0; 

		while (que.stkIn_->top_ != 0) {
			que.stkIn_->POP(cache); 
			que.stkOut_->PUSH(cache); 
		}
		que.stkIn_->PUSH(x); 
	}
	else { // unable to enqueue; 
		throw std::bad_alloc(); 
	}
}
void dequeue(DStkQue& que, int& x)
{
	if (!que.stkOut_->Sempty()) { // stkOut nonempty; 
		que.stkOut_->POP(x); 
	}
	else if (!que.stkIn_->Sempty()) {// stkOut empty, stkIn nonempty; 
		int cache = 0;

		while (que.stkIn_->top_ != 0) {
			que.stkIn_->POP(cache);
			que.stkOut_->PUSH(cache);
		}

		que.stkOut_->POP(x);
	}
	else { // there is nothing to pop; 
		throw std::bad_alloc(); 
	}
}
bool queue_empty(const DStkQue que)
{
	return (que.stkIn_->Sempty() && que.stkOut_->Sempty()); 
}