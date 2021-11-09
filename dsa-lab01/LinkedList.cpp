#include<iostream>
#include"LinkedList.h"

using namespace std;

NODE* createNode(int data)
{
	NODE* newNode = new NODE();
	newNode->key = data;
	newNode->p_next = NULL;

	return newNode;
}

List* createList(NODE* p_node)
{
	List* newList = new List();
	newList->p_head = p_node;
	newList->p_tail = p_node;

	return newList;
}

bool addHead(List* &L, int data)
{
	NODE* newNode = createNode(data);

	if (L->p_head == NULL)
	{
		L->p_head = newNode;
		L->p_tail = newNode;
	}
	else
	{
		newNode->p_next = L->p_head;
		L->p_head = newNode;
	}
	
	return true;
}

bool addTail(List* &L, int data)
{
	NODE* newNode = createNode(data);

	if (L->p_tail == NULL)
	{
		L->p_head = newNode;
		L->p_tail = newNode;
	}
	else
	{
		L->p_tail->p_next = newNode;
		L->p_tail = newNode;
	}

	return true;
}

void removeHead(List* &L)
{
	if (L->p_head == NULL)
	{
		return;
	}

	if (L->p_head->p_next == NULL)
	{
		L->p_head = NULL;
		L->p_tail = NULL;
		return;
	}

	L->p_head = L->p_head->p_next;
}

void removeTail(List* &L)
{
	if (L->p_head == NULL)
	{
		return;
	}

	if (L->p_head->p_next == NULL)
	{
		L->p_head = NULL;
		L->p_tail = NULL;
		return;
	}

	NODE* tmpNode = L->p_head;

	while (tmpNode->p_next != L->p_tail)
	{
		tmpNode = tmpNode->p_next;
	}

	tmpNode->p_next = NULL;
	L->p_tail = tmpNode;
}

void removeAll(List* &L)
{
	L->p_head = NULL;
	L->p_tail = NULL;
}

void removeBefore(List*& L, int val)
{
	if (L->p_head == NULL || L->p_head->p_next == NULL || L->p_head->key == val)
	{
		return;
	}

	if (L->p_head->p_next->key == val)
	{
		L->p_head = L->p_head->p_next;
	}

	NODE* tmpNode = L->p_head;

	while (tmpNode->p_next->p_next != NULL && tmpNode->p_next->p_next->key != val)
	{
		tmpNode = tmpNode->p_next;
	}

	if (tmpNode->p_next->p_next != NULL && tmpNode->p_next->p_next->key == val)
	{
		tmpNode->p_next = tmpNode->p_next->p_next;
	}
}

void removeAfter(List*& L, int val)
{
	if (L->p_head == NULL || L->p_head->p_next == NULL)
	{
		return;
	}

	NODE* tmpNode = L->p_head;

	while (tmpNode->p_next != NULL && tmpNode->key != val)
	{
		tmpNode = tmpNode->p_next;
	}

	if (tmpNode->p_next != NULL && tmpNode->key == val)
	{
		tmpNode->p_next = tmpNode->p_next->p_next;
	}
}

bool addPos(List* &L, int data, int pos)
{
	NODE* newNode = createNode(data);

	if (pos == 0)
	{
		newNode->p_next = L->p_head;
		L->p_head = newNode;

		return true;
	}

	int count = 0;
	NODE* tmpNode = L->p_head;

	while (tmpNode->p_next != NULL && count != pos - 1)
	{
		tmpNode = tmpNode->p_next;
		++count;
	}

	if (count == pos - 1)
	{
		newNode->p_next = tmpNode->p_next;
		tmpNode->p_next = newNode;
		return true;
	}

	return false;
}

void removePos(List*& L, int pos)
{
	if (pos == 0)
	{
		L->p_head = L->p_head->p_next;
		return;
	}

	int count = 0;
	NODE* tmpNode = L->p_head;

	while (tmpNode->p_next->p_next != NULL && count != pos - 1)
	{
		tmpNode = tmpNode->p_next;
		++count;
	}

	if (count == pos - 1)
	{
		tmpNode->p_next = tmpNode->p_next->p_next;
	}
}

bool addBefore(List*& L, int data, int val)
{
	NODE* newNode = createNode(data);

	if (L->p_head == NULL)
	{
		return false;
	}

	if (L->p_head->key == val)
	{
		newNode->p_next = L->p_head;
		L->p_head = newNode;
		
		return true;
	}

	NODE* tmpNode = L->p_head;

	while (tmpNode->p_next != NULL && tmpNode->p_next->key != val)
	{
		tmpNode = tmpNode->p_next;
	}

	if (tmpNode->p_next != NULL && tmpNode->p_next->key == val)
	{
		newNode->p_next = tmpNode->p_next;
		tmpNode->p_next = newNode;
		
		return true;
	}

	return false;
}

bool addAfter(List*& L, int data, int val)
{
	NODE* newNode = createNode(data);

	if (L->p_head == NULL)
	{
		return false;
	}

	if (L->p_head->key == val)
	{
		newNode->p_next = L->p_head->p_next;
		L->p_head->p_next = newNode;

		return true;
	}

	NODE* tmpNode = L->p_head;

	while (tmpNode->p_next != NULL && tmpNode->key != val)
	{
		tmpNode = tmpNode->p_next;
	}

	if (tmpNode->key == val)
	{
		newNode->p_next = tmpNode->p_next;
		tmpNode->p_next = newNode;

		return true;
	}

	return false;
}

void printList(List* L)
{
	NODE* tmpNode = L->p_head;
	
	if (L->p_head == NULL)
	{
		return;
	}

	while (tmpNode != NULL)
	{
		cout << tmpNode->key << "\t";
		tmpNode = tmpNode->p_next;
	}

	cout << endl;
}

int countElements(List* L)
{
	NODE* tmpNode = L->p_head;
	int count = 1;

	if (L->p_head == NULL)
	{
		return 0;
	}

	while (tmpNode->p_next != NULL)
	{
		tmpNode = tmpNode->p_next;
		++count;
	}

	return count;
}

bool removeElements(List*& L, int key)
{
	if (L->p_head == NULL)
	{
		return true;
	}

	if (L->p_head->p_next == NULL)
	{
		if (L->p_head->key == key)
		{
			L->p_head = NULL;
			L->p_tail = NULL;
		}

		return true;
	}

	NODE* currentNode = L->p_head, *prevNode = NULL;

	while (currentNode != NULL)
	{
		if (currentNode->key == key)
		{
			if (prevNode != NULL) {
				prevNode->p_next = currentNode->p_next;
			}
			else
			{
				L->p_head = currentNode->p_next;
			}
		}

		prevNode = currentNode;
		currentNode = currentNode->p_next;

	}

	

	return true;
}

List* reverseList(List* L)
{
	if (L->p_head == NULL)
	{
		return NULL;
	}

	if (L->p_head->p_next == NULL)
	{
		return L;
	}

	NODE* currentNode = L->p_head;
	NODE* nextNode = NULL;
	NODE* prevNode = NULL;

	while (currentNode->p_next != NULL)
	{
		nextNode = currentNode->p_next;
		currentNode->p_next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}

	currentNode->p_next = prevNode;
	L->p_head = currentNode;

	return L;
}

void removeDuplicate(List*& L)
{
	NODE *tmpNode1, *tmpNode2;
	tmpNode1 = L->p_head;

	while (tmpNode1 != NULL && tmpNode1->p_next !=NULL)
	{
		tmpNode2 = tmpNode1;

		while (tmpNode2 != NULL)
		{
			tmpNode2 = tmpNode2->p_next;

			if(tmpNode2->key == tmpNode1->key)
			{
				tmpNode2->p_next == tmpNode2->p_next->p_next;
			}
		}

		tmpNode1 = tmpNode1->p_next;
	}
}