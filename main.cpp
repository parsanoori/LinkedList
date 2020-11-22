#include<iostream>
using namespace std;

#include"LinkedList.h"

int main()
{
	LinkedList list1{};
	list1.add(0);
	list1.add(1);
	list1.add(3);
	list1.add(4);

	list1.print();
	list1.change(0,10);
	list1.print();
	list1.change(3,13);
	list1.print();

	return 0;
}
