#include <iostream>
//#include <algorithm>
#include "seq_queue.h"

using namespace std;

int main()
{
	Queue<char> q(4);
	q.Push('A');
	q.Push('B');

	cout << q.Front() << ", " << q.Rear() << endl;
	q.Push('C');
	cout << q.Front() << ", " << q.Rear() << endl;
	q.Push('D');
	cout << q.Front() << ", " << q.Rear() << endl;
	q.Push('E');
	q.Push('F');
	cout << q.Front() << ", " << q.Rear() << endl;
	return 0;
}
