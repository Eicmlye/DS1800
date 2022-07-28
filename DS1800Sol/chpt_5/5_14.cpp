#include <iostream>
#include "5_14.h"

GLList build(void)
{
	LNode* cache = nullptr;
	GLList result = new LNode('\0');
	LNode* mov = result; 
	char ch = '\0'; 

	if ((ch = getchar()) != '(') {
		cache = new LNode(' '); 
		mov->next_ = cache; 

		return result; 
	}

	while ((ch = getchar()) != ')') {
		if (ch == '(') {
			ungetc(ch, stdin); 
			cache = new LNode(build()); 
			mov->next_ = cache; 
			mov = mov->next_; 
		}
		else if (ch == ',') {
			continue; 
		}
		else {
			cache = new LNode(ch); 
			mov->next_ = cache; 
			mov = mov->next_; 
		}
	}

	return result; 
}