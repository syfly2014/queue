
//��ʽ���нڵ�Ķ���
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