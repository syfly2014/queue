/*ѭ�����еĶ��壬�����ʱ�����Ǳ������������ʱ��һ����λ*/

#ifndef CIRQUEUE
#define CIRQUEUE

template <class T> class CirQueue
{
	int size;
	int front;
	int back;
	T* contain;
public:
	CirQueue() :size(0), front(0), back(0), contain(NULL){}
	CirQueue(int maxsize);

	void EnQueue(T& element);
	T DelQueue();
	T& GetFront();

	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
};

template <class T> CirQueue<T>::CirQueue(int maxsize)
{
	size = maxsize + 1;
	front = back = 0;
	contain = new T[maxsize + 1];
}

template <class T> void CirQueue<T>::EnQueue(T& element)
{
	assert(!IsFull());
	contain[back] = element;
	back = (back + 1) % size;//ѭ��
}

template<class T> T CirQueue<T>::DelQueue()
{
	T value = contain[front];
	front = (front + 1) % size;

	return value;
}

template <class T> T& CirQueue<T>::GetFront()
{
	assert(!IsEmpty());
	return contain[front];
}

template <class T> void CirQueue<T>::MakeEmpty()
{
	front = back = 0;
}

template <class T> bool CirQueue<T>::IsEmpty()
{
	return front == back;
}

template <class T> bool CirQueue<T>::IsFull();
{
	return (back + 1) % size == front;
}
#endif