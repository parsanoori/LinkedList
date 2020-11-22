#include "LinkedList.h"
/***
 * Due to ease of typing and reading the
 * comments I alias TC as Time Complexity
 */

struct LinkedList::Node** LinkedList::getAddressOfPtr(int index){
	if (index >= size)
		throw std::out_of_range("Index is bigger than size");

	struct Node** pp = &first;

	// iteration happens by the amount index which takes O(n)
	for (int i = 0; i < index; i++)
		pp = &(*pp)->next;

	return pp;
}

/*
 * Since Other parts of the function than
 * the loop have the time complexity of 
 * O(1) the function has the time complexity
 * of O(n) 
*/
void LinkedList::add(int x)
{
	struct Node** pp = &first;
	while (*pp) // iterating through all nodes needs time complexity of O(n)
		pp = &(*pp)->next;
	*pp = new Node { x, nullptr };
	size++;
}

/**
 * Other than iteration all works are in
 * TC of O(n) hence the function takes TC
 * of O(n).
 */
bool LinkedList::remove(int index)
{
	if (index >= size)
		return false;

	struct Node** pp = &first;

	// iteration happens by the amount index which takes O(n)
	for (int i = 0; i < index; i++)
		pp = &(*pp)->next;

	(*pp) = (*pp)->next;
	return true;
}

int LinkedList::get(int index)
{
	if (index >= size)
		return false;

	struct Node** pp = &first;

	for
}
