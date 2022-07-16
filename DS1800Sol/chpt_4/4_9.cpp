#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "4_9.h"

void freqToFile(const char* str, const char* filename)
{
	/* allocate frequency counter */
	unsigned int* freq = new unsigned int[36];
	if (freq == nullptr) {
		throw std::bad_alloc(); 
	}
	/* initialize counter */
	size_t index = 0; 
	for (index = 0; index < 36; ++index) {
		freq[index] = 0; 
	}

	/* count frequency */
	index = 0; 
	while ((str[index] >= 'A' && str[index] <= 'Z') || (str[index] >= '0' && str[index] <= '9')) {
		if (str[index] >= '0' && str[index] <= '9') {
			++freq[26 + str[index] - '0']; 
		}
		else {
			++freq[str[index] - 'A'];
		}

		++index; 
	}

	/* send to file */
	FILE* fp = fopen(filename, "w+");
	if (fp == nullptr) {
		throw std::bad_alloc(); 
	}

	fprintf(fp, "character\tfrequency\n"); 
	for (index = 0; index < 36; ++index) {
		fprintf(fp, "%c: \t\t\t%u\n", (index < 26) ? 'A' + (char)index : '0' + (char)index - 26, freq[index]);
	}

	fclose(fp); 

	return; 
}