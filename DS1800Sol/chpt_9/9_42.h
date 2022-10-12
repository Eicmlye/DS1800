#ifndef DS_9_42_H_
#define DS_9_42_H_

#include "chpt_tag.h"

enum hashFlag: short
{
	EMPTY = 0,
	INUSE = 1,
	DELETED = 2
};

typedef struct hashNode {
	int data_ = 0;
	hashFlag flag_ = EMPTY;
} hashNode;

typedef struct ht {
	hashNode* head_ = nullptr;
	size_t size_ = 0;
	size_t capacity_ = 0;
} *hashTable;

hashTable initHash(size_t capacity = 10);
void destroyHash(hashTable table);

bool hashFind(hashTable table, int data);
bool hashInsert(hashTable table, int data);
bool hashDelete(hashTable table, int data);

#endif
