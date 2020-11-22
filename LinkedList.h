#ifndef LinkedListClass
#define LinkedListClass

#include<stdexcept>

class LinkedList {
	struct Node {
		int x;
		struct Node* next;
	};

	struct Node* first = nullptr;
	int size = 0;

	struct Node** getAddressOfPtr(int index); 

    public:

	void add(int x);
	void remove(int index);
	int get(int index);
	int search(int x);
	void change(int index, int x);
};

#endif
