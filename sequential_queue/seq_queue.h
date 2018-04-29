#ifndef seq_queue_h
#define seq_queue_h

//#include <algorithm>

//using namespace std;

template <class T>
class Queue
{
public:
	Queue(int queueCap=10);
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& item);
	void Pop();

private:
	T *queue;
	int front;
	int rear;
	int cap;
};

template <class T>
Queue<T>::Queue(int queueCap):cap(queueCap)
{
	if(cap < 1)
		throw "Queue cap must be > 0";
	queue = new T[cap];
	front = rear = 0;
}

template <class T>
inline bool Queue<T>::IsEmpty() const
{
	return front == rear;
}

template <class T>
void Queue<T>::Push(const T& item)
{
	if((rear + 1) % cap == front)
	{
		//double the cap
		T* newQueue = new T[2*cap];
		int start = (front+1) % cap;
		if(start < 2)
			std::copy(queue+start, queue+start+cap-1, newQueue);
		else
		{
			std::copy(queue+start, queue+cap, newQueue);
			std::copy(queue, queue+rear+1, newQueue+cap-start);
		}
		front = 2 * cap - 1;
		rear = cap - 2;
		cap *= 2;
		delete[] queue;
		queue = newQueue;
	}
	rear = (rear+1) % cap;
	queue[rear] = item;
}

template <class T>
inline T& Queue<T>::Front() const
{
	if(IsEmpty())
		throw "Queue is empty. No front element";
	return queue[(front + 1) % cap];
}

template <class T>
inline T& Queue<T>::Rear() const
{
	if(IsEmpty())
		throw "Queue is empty. No rear element.";
	return queue[rear];
}

template <class T>
void Queue<T>::Pop()
{
	if(IsEmpty())
		throw "Queue is empty. No front element.";
	front = (front+1) % cap;
	queue[front].~T();
}

#endif
