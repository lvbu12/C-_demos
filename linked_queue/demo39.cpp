#include <iostream>
#include "QueueLi.h"

using namespace std;

int main()
{
	cout << "测试链式队列：" << endl;
	Queue<int> myQ;
	for(int i=1; i<10; ++i)
		myQ.enqueue(i);

	cout << myQ.getFront() << ", " << myQ.getRear() << endl;

	myQ.dequeue();

	cout << myQ.getFront() << ", " << myQ.getRear() << endl;

	for(int i=1; i<10; ++i)
		cout << myQ.dequeue() << "\t";
	cout << endl;

	return 0;
}
