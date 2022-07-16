#ifndef DS_2_4_H_
#define DS_2_4_H_

#include "chpt_tag.h"

typedef struct Letter {
	char data = '\0';
	Letter* next = nullptr;
} Letter, *Word;

Letter* getIntersect(Word str1, Word str2); 

#endif