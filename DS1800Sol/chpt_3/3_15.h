#ifndef DS_3_15_H_
#define DS_3_15_H_

#include <iostream>

struct Stack {
	int* stk_; 
	size_t size_; 
	size_t top_;

	Stack(size_t size) : 
		size_(size), 
		top_(0)
	{
		stk_ = new int[size_]; 
		if (stk_ == nullptr) {
			throw std::bad_alloc();
		}
		for (size_t index = 0; index < size_; ++index) {
			stk_[index] = 0; 
		}
	}

	void PUSH(const int x)
	{
		if (top_ == size_) { // full stack; 
			throw std::bad_alloc();
		}

		stk_[top_] = x; 
		++top_; 

		return; 
	}
	void POP(int& x)
	{
		if (top_ == 0) { // empty stack; 
			throw std::bad_alloc();
		}

		x = stk_[top_ - 1]; 
		--top_; 

		return; 
	}
	bool Sempty(void)
	{
		return (top_ == 0);
	}
};

struct DStkQue {
	Stack* stkIn_; 
	Stack* stkOut_; 

	DStkQue(size_t size) 
	{
		stkIn_ = new Stack(size);
		stkOut_ = new Stack(size);
	}
};

void enqueue(DStkQue& que, const int x); 
void dequeue(DStkQue& que, int& x); 
bool queue_empty(const DStkQue que); 

#endif