#include <iostream>
using namespace std;

#define maxsize 10
int heapsize;
int heap[maxsize];

void percolatedown(int hole)
{
	int child;
	int temp = heap[hole];

	for (; hole * 2 <= heapsize; hole = child)
	{
		child = hole * 2;
		if (child != heapsize && heap[child + 1] < heap[child])
		{
			child++;
		}
		if (heap[child] < temp)
		{
			heap[hole] = heap[child];
		}
		else
		{
			break;
		}
	}
	heap[hole] = temp;
}

void build()
{
	int i;

	for (i = heapsize / 2; i > 0; i--)
	{
		percolatedown(i);
	}
}

void initialise()
{
	int i;
	cout << "Enter the size of the heap\n";
	cin >> heapsize;
	cout << "Enter elements:\n";
	for (i = 1; i <= heapsize; i++)
	{
		cin >> heap[i];
	}
	build();
}

void insert()
{
	int x;
	int hole;
	if (heapsize == maxsize)
	{
		cout << "Heap is full\n";
	}
	else
	{
		cout << "Enter item to insert";
		cin>>x;
		hole = ++heapsize;
		for (; hole > 1 && x < heap[hole / 2]; hole = hole / 2)
		{
			heap[hole] = heap[hole / 2];
		}
		heap[hole] = x;
	}
}

void delmin(int &firstterm)
{
	if (heapsize == 0)
	{
		cout << "Heap is empty\n";
	}
	else
	{
		firstterm=heap[1];
		heap[1]=heap[heapsize--];
		percolatedown(1);
	}
}

void minitem()
{
	cout << "Minimum item: " << heap[1] << "\n";
}

void display()
{
	cout << "Index	Element\n";
	for (int i = 1; i <= heapsize; i++)
	{
		cout << i << "\t" << heap[i] << "\n";
	}
}

int main()
{

	int ch, min=0;

	while (1)
	{
		cout << "Minheap operations:\n";
		cout << "1) Buildheap\n";
		cout << "2) Insert\n";
		cout << "3) Display\n";
		cout << "4) Minimum item\n";
		cout << "5) Deletemin\n";
		cout << "6) Exit\n";
		cin>>ch;
		switch (ch)
		{
		case 1:
			initialise();
			break;
		case 2:
			insert();
			break;
		case 3:
			display();
			break;
		case 4:
			minitem();
			break;
		case 5:
			delmin(min);
			break;
		case 6:
			exit(0);
		default:
			cout << "Wrong choice\n";
			break;
		}
	}

	return 0;
}
