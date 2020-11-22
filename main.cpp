#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
	LinkedList list1 {};
	list1.add(0);
	list1.add(0);
	list1.add(1);
	list1.add(2);
	list1.add(1);
	list1.add(0);

	list1.print();
	
	list1.removeRepeats();
	list1.print();

	return 0;
}
