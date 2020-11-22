#include "LinkedList.h"
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
		while (*pp2){
			if ((*pp2)->x == value) {
				next = (*pp2)->next;
				delete *pp2;
				*pp2 = next;
				size--;
			} else pp2 = &(*pp2)->next;
		}
		pp1 = &(*pp1)->next;
	}
}



