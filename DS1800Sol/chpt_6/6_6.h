#ifndef DS_6_6_H_
#define DS_6_6_H_

#include "chpt_tag.h"

size_t* buildParent(size_t* L, size_t* R, size_t N); 

bool isChild(size_t* L, size_t* R, size_t N, size_t u, size_t v); 

#endif