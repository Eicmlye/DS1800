#ifndef DS_7_2_H_
#define DS_7_2_H_

#include "chpt_tag.h"

struct ALGraphEdge {
	size_t vertex_ = 0;
	ALGraphEdge* next_ = nullptr;
};

template <typename DataType>
struct ALGraphVertex {
	DataType data_;
	ALGraphEdge* edge_ = nullptr;
};

template <typename DataType>
struct ALGraph { // Graph in Adjacency List form;
	bool directed_ = false;
	size_t nodeNum_ = 0;
	ALGraphVertex<DataType>* head_ = nullptr;
};

template <typename DataType>
ALGraph<DataType> buildALGraph(bool directed = false);

#endif
