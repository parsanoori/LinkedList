#include <iostream>
using namespace std;
struct DoubleNode {
	int x;
	struct DoubleNode* next;
	struct DoubleNode* prev;
};

/**
 * One time iteration of the list hence
 * the time complexity is O(n)
 */
bool isPalindrome(struct DoubleNode* start, struct DoubleNode* last, int n)
{
	for (int i = 0; i < n / 2; i++)
		if (start->x != last->x)
			return false;
	return true;
}

struct Node {
	int x;
	struct Node* next;
};


/**
 * A simple iteration depending on index
 * which is at most n hence it has the time 
 * complexity of O(n)
 */
int get(struct Node* first,int index )
{
	
	struct Node* iter = first;
	for(int i =0; iter ;i++) 
		if (i==index)
			return iter->x;
	return false;
		
		
}

/**
 * Since the loop happens n/2 time and
 * each time it takes n n-1 ... n/2
 * times, it will take O(n^2)
 */
bool isPalindrome(struct Node* first,int size)
{
	struct Node* it = first;
	for(int i=0; i<size/2; i++)
		if (it->x != get(first,size-i-1))
			return false;
	return true;
}

int main()
{
	struct DoubleNode *node1 = new DoubleNode { 1, nullptr, nullptr }, *node2 = new DoubleNode { 2, nullptr, nullptr }, *node3 = new DoubleNode { 1, nullptr, nullptr };
	node1->next = node2;
	node2->next = node3;
	node3->prev = node2;
	node2->prev = node1;

	cout << isPalindrome(node1, node3, 3) << endl;

	struct Node *n1 = new Node{1,nullptr},
		    *n2 = new Node{2,nullptr},
		    *n3 = new Node{1,nullptr};

	n1->next = n2;
	n2->next = n3;

	cout << isPalindrome(n1,3);

}
