/*
	S1 作为入队容器, S2 作为出队容器。当 S1 为空时, 入队直接入栈 S1 即可; 当 S1 非空, 先将 S1 的元素出栈并依次入栈到 S2, 再将要入队的元素入栈 S1。当 S2 非空时, 出队直接出栈 S2 即可; 当 S2 为空, 先将 S1 中的元素出栈并依次入栈到 S2, 再将 S2 出栈一次即可. 验证队列为空即验证两个栈均为空.
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
