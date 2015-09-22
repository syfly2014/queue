/*定义链式队列*/

#include "LinkQueueNode.h"
#include <assert.h>

#ifndef LINKQUEUE
#define LINKQUEUE

template <class T> class LinkQueue
{
private:
	LinkQueueNode<T> * front;
	LinkQueueNode<T> * back;
public:
	LinkQueue(): front(NULL),back(NULL){}
	
	void EnQueue(T element);
	T DelQueue();
	T GetFront();

	void MakeEmpty();
	bool IsEmpty();
};

template <class T> void LinkQueue<T>::EnQueue(T element)
{
	LinkQueueNode<T> *add = new LinkQueueNode<T>(element);
	if (back == NULL)
	{
		front = back = add;
	}
	else
	{
		back->link = add;
		back = add;
	}
}

template <class T> T LinkQueue<T>::DelQueue()
{
	assert(!IsEmpty());

	//T value;
	//value = front->data;
	//front = front->link;

	LinkQueueNode<T> *old = front;
	T data = old->data;

	front = front->link;
	if (back == old)
		back == NULL;
	
	delete old;
	
	return data;
}

template <class T> T LinkQueue<T>::GetFront()
{
	assert(!IsEmpty());

	return front->data;
}

template <class T> void LinkQueue<T>::MakeEmpty()
{
	while (!this->IsEmpty())
	{
		this->DelQueue();
	}
}

template <class T> bool LinkQueue<T>::IsEmpty()
{
	return front == NULL;
}

#endif