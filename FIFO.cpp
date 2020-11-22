#include<iostream>
using namespace std;

class FIFO {
	struct Node {
		int x;
		struct Node* next;
	};
	struct Node *first = nullptr, *last = nullptr;

    public:
	// All works are in O(1)
	void enqeue(int x)
	{
		Node* n = new Node { x, nullptr };
		if (last == nullptr){
			last = n;
			first = n;
		}
		else{
		last->next = new Node { x, nullptr };
		last = last->next;
		}
	}

	// All works are in O(1)
	int deqeue()
	{
		if (first == nullptr)
			return -1;
		int val = first->x;
		struct Node* second = first->next;
		delete first;
		first = second;
		return val;
	}
};

int main()
{
	FIFO q;
	q.enqeue(1);
	q.enqeue(2);
	q.enqeue(3);
	q.enqeue(4);
	q.enqeue(5);
	q.enqeue(6);
	
	cout << q.deqeue() << endl;
	cout << q.deqeue() << endl;
	cout << q.deqeue() << endl;
	cout << q.deqeue() << endl;
	cout << q.deqeue() << endl;
	cout << q.deqeue() << endl;

}
