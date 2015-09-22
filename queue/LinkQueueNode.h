
//链式队列节点的定义
#ifndef LINKQUEUENODE
#define LINKQUEUENODE

template <class T> class LinkQueueNode
{
public:
	T data;
	LinkQueueNode<T> * link;

	LinkQueueNode(T& value) :link(NULL), data(value){}
};

#endif