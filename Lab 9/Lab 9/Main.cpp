/***********************************************

	Class DoublyList

************************************************/

#include "DoublyList.h"

#include <iostream>
using namespace std;

void test(DoublyList& intList, int key);

int main()
{
	DoublyList intList;

	cout << "INSERT...\n";
	intList.insertBack(1);
	intList.insertBack(2);
	intList.insertBack(3);
	intList.insertBack(4);
	intList.insertBack(5);
	intList.insertBack(6);
	intList.insertBack(7);

	cout << "\nPRINT LIST FORWARD:   ";
	intList.print();
	cout << "Print list backwards: ";
	intList.reversePrint();

	cout << "\nDelete and search deleted item...\n";
	test(intList, 1);
	test(intList, 4);
	test(intList, 6);
	test(intList, 7);
	test(intList, 3);
	test(intList, 2);
	test(intList, 5);
	
	DoublyList emptyList;
	cout << "\nEMPTY LIST";
	cout << "\nPRINT LIST FORWARD:   ";
	emptyList.print();
	cout << "PRINT LIST BACKWARDS: ";
	emptyList.reversePrint();

	cout << endl;
	system("Pause");
	return 0;
}

void test(DoublyList& intList, int key)
{
	cout << "\nSEARCH " << key << "... ";
	if (intList.search(key)) cout << "found";
	else cout << "not found"; 
	cout << "\nDELETE " << key << "...\n";
	intList.deleteNode(key);
	cout << "PRINT LIST FORWARD:   ";
	intList.print();
	cout << "PRINT LIST BACKWARDS: ";
	intList.reversePrint();
	cout << "SEARCH " << key << "... ";
	if (intList.search(key)) cout << "found";
	else cout << "not found";
	cout << endl;
}