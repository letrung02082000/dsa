#include <iostream>
#include "LinkedList.h"

using namespace std;

//void swap(int* a, int* b);
//int* sum(int* a, int* b);
//void inputArray(int* a, int& n);
//void printArray(int* a, int n);
//int* findMax(int* a, int n);
//int* findLongestAscendingSubarray(int* a, int n, int& length);


int main()
{
	/*int n;
	cout << "Nhap do dai mang: ";
	cin >> n;

	int* a = new int[n];
	inputArray(a, n);

	int length;
	int *res = findLongestAscendingSubarray(a, n, length);
	cout << "Ket qua:" << endl;
	printArray(res, length);*/

	NODE* head = createNode(10);
	List* list = createList(head);

	addHead(list, 15);
	addHead(list, 20);
	addTail(list, 25);
	addTail(list, 9);
	addTail(list, 10);
	addAfter(list, 5, 10);
	removeHead(list);
	removeTail(list);
	//removeAll(list);
	//removeBefore(list, 5);
	addPos(list, 30, 2);
	//removePos(list, 2);
	addBefore(list, 50, 5);
	addAfter(list, 100, 5);
	removeElements(list, 50);

	printList(list);
	cout << endl << countElements(list) << endl;
	//List* newList = reverseList(list);
	//printList(newList);
	
	system("pause");
	return 0;
}


























void swap(int* a, int* b)
{
	int tmp = *a;
	a = b;
	*b = tmp;
}

int* sum(int* a, int* b)
{
	int res = 0;
	res = *a + *b;

	return &res;
}

void inputArray(int* a, int& n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void printArray(int* a, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = " << a[i] << endl;
	}
}

int* findMax(int* a, int n)
{
	int max = a[0];
	int i = 1;

	while (i < n)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		++i;
	}

	return &max;
}

int* findLongestAscendingSubarray(int* a, int n, int& length)
{
	int subarray[100];
	length = 0;

	for (size_t i = 0; i < n; i++)
	{
		int firstElement = a[i];
		int prevElement = firstElement;
		subarray[0] = firstElement;
		int k = 0;

		for (size_t j = i + 1; j < n; j++)
		{
			if (a[j] >= prevElement)
			{
				int tmp = a[j];
				subarray[++k] = tmp;
				prevElement = a[j];
			}
		}

		if (k > length)
		{
			length = k;
		}
	}

	return subarray;
}