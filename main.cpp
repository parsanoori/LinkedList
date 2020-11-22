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
	
	list1.add(3);
	list1.reverse();
	list1.print();

	LinkedList e,o;
	list1.split(o,e);

	e.print();
	o.print();
	return 0;
}
