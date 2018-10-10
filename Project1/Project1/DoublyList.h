#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
	Node() : data(0), prev(nullptr), next(nullptr) {}
	Node(int theData, Node *prevLink, Node *nextLink)
		: data(theData), prev(prevLink), next(nextLink) {}
	Node *getNext() const { return next; }
	Node *getPrev() const { return prev; }
	int getData() const { return data; }
	void setData(int theData) { data = theData; }
	void setNext(Node *nextLink) { next = nextLink; }
	void setPrev(Node *prevLink) { prev = prevLink; }
	~Node() {}
private:
	int data;
	Node *next;
	Node *prev;
};

class DoublyList
{
public:
	DoublyList();

	void insertBack(int newData);
	bool search(int searchData) const;
	void deleteNode(int deleteData);
	void print() const;
	void reversePrint() const;

	void destroyList();
	~DoublyList();

private:
	Node *first;	// pointer to the first node on the list
	Node *last;		// pointer to the last node on the list
	int count;		// number of nodes in the list
};

#endif