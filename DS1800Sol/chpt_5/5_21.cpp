#include <iostream>
#include "5_21.h"

Matrix fastTSpMat(Matrix mat, size_t n, size_t t)
{
	Matrix result = new MatNode[t];
	size_t* numCol = new size_t[n]; 
	size_t index = 0; 
	for (index = 0; index < n; ++index) {
		numCol[index] = 0; 
	}

	for (index = 0; index < t; ++index) {
		// count elements in each column; 
		if (mat[index].col_ != n) {
			++numCol[mat[index].col_ - 1];
		}
	}
	// find where the first element of each col should be in result; 
	for (index = 1; index < n - 1; ++index) {
		numCol[index] += numCol[index - 1];
	}
	for (index = 0; index < n - 1; ++index) {
		numCol[n - index - 1] = numCol[n - index - 2]; 
	}
	numCol[0] = 0; 

	size_t curCol = 0; 
	for (index = 0; index < t; ++index) {
		curCol = numCol[mat[index].col_ - 1]; 
		result[curCol].row_ = mat[index].col_; 
		result[curCol].col_ = mat[index].row_;
		result[curCol].data_ = mat[index].data_;
		++numCol[mat[index].col_ - 1]; 
	}

	return result; 
}