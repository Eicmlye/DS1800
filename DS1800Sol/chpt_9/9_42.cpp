#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "9_42.h"

hashTable initHash(size_t capacity)
{
	hashTable HT = new ht;
	HT->capacity_ = capacity;
	HT->size_ = 0;
	HT->head_ = new hashNode[HT->capacity_];
	for (size_t index = 0; index < HT->capacity_; ++index) {
		HT->head_[index].data_ = 0;
		HT->head_[index].flag_ = EMPTY;
	}

	return HT;
}
void destroyHash(hashTable table)
{
	delete[] table->head_;
	delete table;

	return;
}

bool hashFind(hashTable table, int data)
{
	size_t inc = 0;
	do {
		if (table->head_[(data + inc) % table->capacity_].flag_ == INUSE) {
			if (table->head_[(data + inc) % table->capacity_].data_ == data) {
				return true;
			}
		}

		++inc;
	} while (table->head_[(data + inc) % table->capacity_].flag_ != EMPTY && inc != table->capacity_);

	return false;
}
bool hashInsert(hashTable table, int data)
{
	size_t inc = 0;
	do {
		if (table->head_[(data + inc) % table->capacity_].flag_ != INUSE) {
			table->head_[(data + inc) % table->capacity_].data_ = data;
			table->head_[(data + inc) % table->capacity_].flag_ = INUSE;

			return true;
		}

		++inc;
	} while (inc != table->capacity_);

	return false;
}
bool hashDelete(hashTable table, int data)
{
	size_t inc = 0;
	do {
		if (table->head_[(data + inc) % table->capacity_].flag_ == INUSE) {
			if (table->head_[(data + inc) % table->capacity_].data_ == data) {
				table->head_[(data + inc) % table->capacity_].flag_ = DELETED;

				return true;
			}
		}

		++inc;
	} while (table->head_[(data + inc) % table->capacity_].flag_ != EMPTY && inc != table->capacity_);

	return false;
}