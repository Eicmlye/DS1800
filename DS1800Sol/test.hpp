#include <iostream>

namespace DS_TEST
{
    template <typename DataType>
    size_t partition(DataType* arr, size_t head, size_t tail, bool (*isnotlt)(DataType, DataType))
    {
        // randomly choose the pivot to optimize run time;
        size_t pivotInd = head + (size_t)((tail - head) * (rand() / (double)RAND_MAX));
        // swap the pivot element to the head position;
        DataType pivot = arr[pivotInd];
        arr[pivotInd] = arr[head];
        arr[head] = pivot;

        // partitioning;
        while (head < tail) {
            while (head < tail && isnotlt(arr[tail], pivot)) {
                --tail;
            }
            arr[head] = arr[tail];
            while (head < tail && isnotlt(pivot, arr[head])) {
                ++head;
            }
            arr[tail] = arr[head];
        }
        arr[head] = pivot;

        return head;
    }

    template <typename DataType>
    void quickSort(DataType* arr, size_t head, size_t tail, bool (*isnotlt)(DataType, DataType))
    {
        if (head < tail) {
            size_t pivotInd = partition<DataType>(arr, head, tail, isnotlt);

            // deal with the front part;
            if (head + 1 < pivotInd) { // to avoid size_t overflow;
                quickSort<DataType>(arr, head, pivotInd - 1, isnotlt);
            }
            // deal with the rear part; 
            if (pivotInd < tail - 1) { // to avoid size_t overflow;
                quickSort<DataType>(arr, pivotInd + 1, tail, isnotlt);
            }
        }

        return;
    }

    template <typename DataType>
    void qksort(DataType* arr, size_t size, bool (*isnotlt)(DataType, DataType))
    { // quick sort API;
        quickSort<DataType>(arr, 0, size - 1, isnotlt);

        return;
    }
}

namespace DS_TEST
{
    // Building process is necessary only if 
    // the original data is in non-sequential structure, 
    // and this process should be customized accordingly; 
    // template <typename ObjectHeader, typename DataType>
    // DataType* buildHeap(ObjectHeader obj) {}

    // arr: the heap followed by unheapified elements; 
    // ind: the node to be examined; 
    // heapSize: the size of the heap; 
    template <typename DataType>
    void heapify(DataType* arr, size_t ind, size_t heapSize, bool (*isnotlt)(DataType, DataType))
    {
        if (2 * ind + 1 >= heapSize) { // if leaf; 
            return; 
        }
        // check if rchild exists; 
        // notice that the data and the heap share the same array; 
        // so noRchild will avoid 
        // misswaping single-child node with elements outside the heap; 
        bool noRchild = false; 
        if (2 * ind + 2 >= heapSize) { // if has no rchild; 
            noRchild = true;
        }

        bool flag = noRchild || isnotlt(arr[2 * ind + 1], arr[2 * ind + 2]);
        // find max child; 
        size_t temp = flag ? 2 * ind + 1 : 2 * ind + 2; 

        if (!isnotlt(arr[ind], arr[temp])) { // if non-heap, swap parent and max child; 
            arr[ind] += arr[temp]; 
            arr[temp] = arr[ind] - arr[temp];
            arr[ind] -= arr[temp];

            // examine child; 
            heapify(arr, temp, heapSize, isnotlt); 
        }

        return; 
    }

    // heap sort API; find the 1st-(heapSize)th min elements; 
    // arr: the heap followed by unheapified elements; 
    // size: the size of arr; 
    // heapSize: the size of the heap; 
    template <typename DataType>
    void heapSort(DataType* arr, size_t size, size_t heapSize, bool (*isnotlt)(DataType, DataType))
    {
        // build heap; 
        std::cout << "Heap building..." << std::endl; 
        for (size_t index = 0; index < heapSize; ++index) {
            heapify(arr, heapSize - index - 1, heapSize, isnotlt);
            std::cout << "step " << index + 1 << ": " << arr << std::endl;
        }
        std::cout << std::endl;

        // sort; 
        for (size_t index = heapSize; index < size; ++index) {
            if (!isnotlt(arr[index], arr[0])) {
                std::cout << "New minimum at " << index + 1 << ": " << arr[index] << std::endl;
                arr[0] += arr[index]; 
                arr[index] = arr[0] - arr[index]; 
                arr[0] -= arr[index]; 
                std::cout << "Swap done: " << arr << std::endl;
                std::cout << "Heap rebuilding..." << std::endl; 
                for (size_t jndex = 0; jndex < heapSize; ++jndex) {
                    heapify(arr, heapSize - jndex - 1, heapSize, isnotlt);
                    std::cout << "step " << jndex + 1 << ": " << arr << std::endl;
                }
                std::cout << std::endl;
            }
        }

        return; 
    }
}