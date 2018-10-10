/*
	Kim, Ji Soo

	CS A250
	October, 9, 2018

	Lab 9
*/

#include "DoublyList.h"

DoublyList::DoublyList()
{
	count = 0;
	first = nullptr;
	last = nullptr;
}

void DoublyList::insertBack(int newData)
{
	Node *newNode = new Node(newData, last, nullptr);

	if (first == nullptr)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->setNext(newNode);
		last = newNode;
	}
	++count;
}

bool DoublyList::search(int searchData) const
{
	Node *current = first;

	while (current != nullptr)
	{
		if (current->getData() == searchData)
			return true;
		else
			current = current->getNext();
	}
	return false;
}

void DoublyList::deleteNode(int deleteData)
{
	if (first == nullptr)
	{
		cerr << "Cannot delete from an empty list." << endl;
	}
	else
	{

		Node *current = first;
		if (first->getData() == deleteData)
		{
			first = first->getNext();

			if (first == nullptr) last = nullptr;
			else first->setPrev(nullptr);

			delete current;
			current = nullptr;
		}
		else
		{
			bool found = false;

			while (current != nullptr && !found)
			{
				if (current->getData() == deleteData)
					found = true;
				else
					current = current->getNext();
			}

			if (current == nullptr)
				cerr << "The item to be deleted is not in the list." << endl;
			else
			{
				if (current != last)
				{
					current->getPrev()->setNext(current->getNext());
					current->getNext()->setPrev(current->getPrev());
				}
				else
				{
					last = current->getPrev();
					last->setNext(nullptr);
				}

				--count;
				delete current;
				current = nullptr;
			}
		}
	}
}

void DoublyList::print() const
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = first;
		while (temp != nullptr)
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		cout << endl;
	}
}

void DoublyList::reversePrint() const
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = last;
		while (temp != nullptr)
		{
			cout << temp->getData() << " ";
			temp = temp->getPrev();
		}
		cout << endl;
	}
}

void DoublyList::destroyList()
{
	Node  *temp = first;
	while (first != nullptr)
	{
		temp = temp->getNext();
		delete temp;
		temp = nullptr;
	}
	count = 0;
	last = nullptr;
}

DoublyList::~DoublyList()
{
	destroyList();
}