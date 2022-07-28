#ifndef DS_5_14_H_
#define DS_5_14_H_

#include "chpt_tag.h"

typedef struct LNode {
	union {
		char ch_;
		LNode* node_;
	};
	LNode* next_; 

	LNode(char ch, LNode* next = nullptr) : ch_(ch), next_(next) {};
	LNode(LNode* node, LNode* next = nullptr) : node_(node), next_(next) {};
} LNode, *GLList;

GLList build(void); 

#endif