#ifndef QUEUELI_H_
#define QUEUELI_H_

template <class T>
class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty() const;
	const T& getFront() const;
	const T& getRear() const;
	void enqueue(const T& x);
	T dequeue();
	void makeEmpty();

private:
	struct ListNode
	{
		T element;
		ListNode *next;
		ListNode(const T& theElement, ListNode *n=0): element(theElement), next(n) {}
	};

	ListNode *front;
	ListNode *back;
};

template <class T>
Queue<T>::Queue()
{
	front = back = 0;
}

template <class T>
Queue<T>::~Queue()
{
	makeEmpty();
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return front == 0;
}

template <class T>
const T& Queue<T>::getFront() const
{
	if(isEmpty())
		throw "Queue is empty.";
	return front->element;
}

template <class T>
const T& Queue<T>::getRear() const
{
	if(isEmpty())
		throw "Queue is empty.";
	return back->element;
}

template <class T>
void Queue<T>::enqueue(const T& x)
{
	if(isEmpty())
		back = front = new ListNode(x);
	else
		back = back->next = new ListNode(x);
}

template <class T>
T Queue<T>::dequeue()
{
	if(isEmpty())
		throw "Queue is empty, can not be dequeued.";

	T frontItem = getFront();
	ListNode* old = front;
	front = front->next;
	delete old;
	return frontItem;
}

template <class T>
void Queue<T>::makeEmpty()
{
	while(!isEmpty())
		dequeue();
}

#endif
