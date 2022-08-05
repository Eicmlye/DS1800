#ifndef DS_TEST_H_
#define DS_TEST_H_ 1

#if DS_TEST_H_ == 0
namespace DS_TEST
{
	template <typename DataType = int>
	static size_t partition(DataType* arr, size_t head, size_t tail, bool (*isnotlt)(DataType, DataType));

	template <typename DataType = int>
	static void quickSort(DataType* arr, size_t head, size_t tail, bool (*isnotlt)(DataType, DataType));

	template <typename DataType = int>
	void qksort(DataType* arr, size_t size, bool (*isnotlt)(DataType, DataType) = [](DataType left, DataType right) -> bool { return left >= right; });
}

#endif

#if DS_TEST_H_ == 1

namespace DS_TEST
{
	// Building process is necessary only if 
	// the original data is in non-sequential structure, 
	// and this process should be customized accordingly; 
	// template <typename ObjectHeader, typename DataType>
	// DataType* buildHeap(ObjectHeader obj);

	template <typename DataType = int>
	void heapify(DataType* arr, size_t ind, size_t heapSize, bool (*isnotlt)(DataType, DataType));

	// heap sort API; 
	template <typename DataType = int>
	void heapSort(DataType* arr, size_t size, size_t heapSize, bool (*isnotlt)(DataType, DataType) = [](DataType left, DataType right) -> bool { return left >= right; });
}

#endif

#include "test.hpp"

#endif