#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "7_2.h"

template <typename DataType>
ALGraph<DataType> buildALGraph(bool directed)
{
	std::cout << "A graph is being built in adjacency list form. " << std::endl;
	std::cout << "Enter the number of vertices in the graph: "; 
	size_t nodeNum = 0;
	// Notice that %zd receives negative numbers bitwise;
	// So negative inputs should be treated independently here;
	if (scanf("%zd", &nodeNum) != 1 && nodeNum == 0) {
		return nullptr;
	}

	// Now nodeNum > 0;
	ALGraph<DataType> result;
}