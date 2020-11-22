#ifndef LinkedListClass
#define LinkedListClass

#include<stdexcept>
#include<iostream>

class LinkedList {
	struct Node {
		int x;
		struct Node* next;
	};

	struct Node* first = nullptr;
	int size = 0;

	struct Node** getAddressOfPtr(int index,const bool isAddCalling) const; 
	void swap(struct Node* left, struct Node* right);
	void reverse(struct Node* forward,int indexForward);

	void split(LinkedList &o,LinkedList& e,struct Node* it,int index)const;


    public:

	void add(int x);
	void remove(int index);
	int get(int index);
	int search(int x);
	void change(int index, int x);
	void print();
	void removeRepeats();
	void reverse();
	void split(LinkedList &o,LinkedList& e);
	int intersection(LinkedList& l2);
	bool detectLoops();
};

#endif
