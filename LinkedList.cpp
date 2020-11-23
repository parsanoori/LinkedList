#include "LinkedList.h"
#include <stdexcept>
/***
 * Due to ease of typing and reading the
 * comments I alias TC as Time Complexity
 */

/*
 * This is a private memner for eaese of
 * my implementation and duplication 
 * prevention. Since other than the 
 * iteration other parts of the function
 * are some constant actions this function
 * takes TC of O(n)
 */
struct LinkedList::Node** LinkedList::getAddressOfPtr(int index, const bool isAddCalling = false)
{
	if (!isAddCalling && index >= size || isAddCalling && index > size)
		throw std::out_of_range("Index is bigger than size");

	struct Node** pp = &first;

	// iteration happens by the amount index which takes O(n)
	for (int i = 0; i < index; i++)
		pp = &(*pp)->next;

	return pp;
}

/**
 * Second and third lines are some
 * constant works hence the function
 * has time complexity of O(n)
 */
void LinkedList::add(int x)
{
	struct Node** pp = getAddressOfPtr(size, true); // TC: O(n)
	*pp = new Node { x, nullptr };
	size++;
}

/**
 * Other than the first line the lines 
 * take TC of O(n) hence the function 
 * has time complexity of O(n)
 */
void LinkedList::remove(int index)
{
	struct Node** pp = getAddressOfPtr(index);
	struct Node* next = (*pp)->next;
	delete *pp;
	(*pp) = next;
	size--;
}

/**
 * The only line has TC of O(n)
 */
int LinkedList::get(int index)
{
	return (*getAddressOfPtr(index))->x;
}

/**
 * The iteration takes TC of O(n)
 * and other parts are constants
 * hence search takes TC of O(n)
 * NOTE: -1 is returned if element
 * if not found
 */
int LinkedList::search(int x)
{
	struct Node** pp = &first;
	int i;
	for (i = 0; i < size && (*pp)->x != x; i++)
		pp = &(*pp)->next;
	return i == size ? -1 : i;
}

/**
 * Search takes O(n) changing vlue takes
 * constant time
 */
void LinkedList::change(int index, int x)
{
	struct Node** pp = getAddressOfPtr(index);
	(*pp)->x = x;
}

/**
 * Iteration takes TC of O(n)
 */
void LinkedList::print()
{
	struct Node** pp = &first;

	std::cout << std::endl
		  << "List size is : " << size << std::endl
		  << "List is : ";
	while (*pp) {
		std::cout << (*pp)->x << " ";
		pp = &(*pp)->next;
	}
	std::cout << std::endl
		  << std::endl;
}

/**
 * Remove repeats
 * Each outer loop happens by the amount
 * of the elements left on the list
 * hence the TC of it is in the form of 
 * 1 + 2 + 3 .... n 
 * so the TC is O(n^2)
 *
 * NOTE: I didn't thoroughly thought of
 * start and end of the sequence but it's
 * preciese enough for the asymptotic notation
 */
void LinkedList::removeRepeats()
{
	struct Node** pp1 = &first;
	struct Node** pp2;
	struct Node* next;
	while (*pp1) {
		int value = (*pp1)->x;
		pp2 = &(*pp1)->next;
		while (*pp2) {
			if ((*pp2)->x == value) {
				next = (*pp2)->next;
				delete *pp2;
				*pp2 = next;
				size--;
			} else
				pp2 = &(*pp2)->next;
		}
		pp1 = &(*pp1)->next;
	}
}

/**
 * Swaps the value of two givcn nodes
 * the TC is obviousy O(1)
 */
void LinkedList::swap(struct Node* left, struct Node* right)
{
	int tmp = left->x;
	left->x = right->x;
	right->x = tmp;
}

/**
 * For each call it should find the element at
 * index of "size - indexForward - 1" which
 * takes the time to iterate to reach it
 * It is called for size/2 times
 * whith indexForward from 0 ... n/2
 * for each of these the iteration takes
 * n n-1 ... n/2 times to reach the end
 * hence the sum of these is the time taken
 * by the func. So the TC is O(n^2)
 */
void LinkedList::reverse(struct LinkedList::Node* forward, int indexForward)
{
	if (indexForward >= size / 2)
		return;
	swap(forward, *getAddressOfPtr(size - indexForward - 1));
	reverse(forward->next, indexForward + 1);
}

/**
 * Simple wrapper for other reverse above
 * hence the TC is O(n^2)
 */
void LinkedList::reverse()
{
	reverse(first, 0);
}

/**
 * Simple iteration forcibly turned to recursion
 * hence the TC is O(n)
 */
void LinkedList::split(LinkedList& o, LinkedList& e, struct LinkedList::Node* it, int index)
{
	if (!it)
		return;

	if (index % 2 == 0)
		e.add(it->x);
	else
		o.add(it->x);

	split(o, e, it->next, index + 1);
}

/**
 * Wrapper of above function
 */
void LinkedList::split(LinkedList& o, LinkedList& e)
{
	LinkedList en, on;
	split(en, on, first, 0);
	e = en;
	o = on;
}

/**
 * Finds index of which this LinkedList intersects
 * with the other.
 * Each for loop execution takes time of 1 .... size | size2
 * times of something some of these are in O(n^2)
 */
int LinkedList::intersection(LinkedList& l2)
{
	int size2 = l2.size, i;

	for (i = 0; i < size && i < size2; i++)
		if (get(size - i - 1) != l2.get(size2 - i - 1))
			break;

	return i == size || i == size2 ? -1 : size - i;
}

/**
 * Floyd's way is used. One fast pointer and other sow
 * fast is steps by 2 and sow by one.
 * Distance increases by 1 one each iteration and starts
 * from 0 <= k <= n once they are both in the cycle
 * if there is a loop once the difference becomes n which
 * means thay they are on the same place in the cycle.
 * This needs at maximum n actions which means the TC is
 * O(n)
 */

bool LinkedList::detectLoops()
{
	Node *s, *f;
	s = f = first;

	while (s && f && f->next) {
		s = s->next; // move slow by one
		f = f->next->next; // move fast by two

		if (s == f) // if they fall in each other
			return true;
	}

	// if iteration stops means list has end
	return false;
}

void LinkedList::removeMiddle(struct LinkedList::Node* it, int i)
{
	if (i == size / 2 - 1) {
		Node* oneAfterMiddle = it->next->next;
		delete it->next;
		it->next = oneAfterMiddle;
		return;
	}
	removeMiddle(it->next, i + 1);
}

/**
 * Simple iteration O(n/2)
 */
void LinkedList::removeMiddle()
{
	if (size % 2 == 0)
		throw std::logic_error("Lenght must be even");
	removeMiddle(first, 0);
}

/**
 * MergeSort for sorting the list
 * lg(n) times the merge will take happpen hence
 * the TC complexity of this function is O(nlogn)
 */
void LinkedList::mergeSort()
{
	struct Node* first = this->first;

	if (first == NULL)
		return;

	struct Node *start1 = nullptr, *end1 = nullptr,
		    *start2 = nullptr, *end2 = nullptr,
		    *prevend = nullptr;

	int gap;
	for (gap = 1; gap < size; gap = gap * 2) { // lg(n) time this will run
		start1 = first;
		while (start1) {
			//setting start1
			bool isFirstIter = false;
			if (start1 == first)
				isFirstIter = true;

			//setting end1
			int counter = gap;
			end1 = start1;
			while (--counter && end1->next)
				end1 = end1->next;

			//setting start2
			start2 = end1->next;
			if (!start2)
				break;

			//setting end2
			counter = gap;
			end2 = start2;
			while (--counter && end2->next)
				end2 = end2->next;

			//start1 of the next iteration
			Node* temp = end2->next;

			merge(start1, end1, start2, end2); // TC: O(lgn)

			if (isFirstIter)
				first = start1;
			else
				prevend->next = start1;

			prevend = end2;
			start1 = temp;
		}
		prevend->next = start1;
	}
}

/**
 * Like any other merge has TC of O(1)
 */
void LinkedList::merge(struct Node*& start1, struct Node*& end1,
    struct Node*& start2, struct Node*& end2)
{

	struct Node *temp = NULL, *end2next = end2->next;

	if (start1->x > start2->x) {
		std::swap(start1, start2);
		std::swap(end1, end2);
	}

	while (start1 != end1 && start2 != end2next) {
		if (start1->next->x > start2->x) {
			temp = start2->next;
			start2->next = start1->next;
			start1->next = start2;
			start2 = temp;
		}
		start1 = start1->next;
	}

	if (start1 == end1)
		start1->next = start2;
	else
		end2 = end1;
}

/**
 * Since the loop happens n/2 time and 
 * each time it takes n n-1 ... n/2
 * times, it will take O(n^2)
 */
bool LinkedList::isPalindrome()
{
	struct Node* it = first;
	for (int i = 0; i < size / 2; i++)
		if (it->x != get(size - i - 1))
			return false;
	return true;
}

