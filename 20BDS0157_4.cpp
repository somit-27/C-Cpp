#include <iostream>
#include <stdlib.h>
using namespace std;

struct stud // structure to store roll numbers of students, to store data dynamically
{
	int roll;
	stud *next; // self refential pointer to store the address of the data to create a link
};

stud *start, *temp, *ptr; // pointers of user defined data type stud

void insertrear() // to insert element at the end
{
    ptr= new stud; // allocate fresh memory to ptr
    if (ptr==NULL) // memory erro
    {
        cout<<"Overflow\n";
    }
    else
    {
        cout<<"Enter roll:\n";
        cin>>ptr->roll; // take the roll number
        ptr->next=NULL; // map next as NULL
        if (start==NULL) // if list is empty
        {
            start=ptr; // start becomes ptr
        }
        else
        {
            temp=start;
            while (temp->next!=NULL) // to travel to end of list
            {
                temp=temp->next;
            }
            temp->next=ptr; // ptr gets attached
        }
    }
}

void display() // to display the linked list
{
	if (start == NULL) // empty list
		cout << "Underflow\n";
	else
	{
		stud *pos;
		for (pos = start; pos != NULL; pos = pos->next) // loop will run from the start till the address mapped to the next pointer of a node is NULL
		{
			cout << pos->roll << "\t";
		}
		cout << "\n";
	}
}

int search(int s) // search elements in the list
{
	int position = 0;
	stud *pos;
	for (pos = start; pos != NULL; pos = pos->next) // loop will run from the start till the address mapped to the next pointer of a node is NULL
	{
		if (pos->roll == s)
		{
            // flag=1;
            return position;
			// cout << "Element found at position: " << position << "\n"; // print the position of the element in the list
			// flag = 1;
		}
		position++;
	}
	// if (flag == 0)
	// {
	// 	// cout << "Element not found\n"; // when element is not found
    //     return -1;
	// }
    return -1;
}

void del(int todel) // deleting node
{
	int pos, counter = 0;
	stud *prev, *aft; //prev and aft will be the nodes previous and after the node we are deleting
	prev = start;
	if (start == NULL)
		cout << "Underflow\n";
	else
	{
        int pos;
        pos=search(todel); // to get the position of the item to delete
        if (pos==-1) // when it does not exists pos will be -1
        {
            cout<<"Element does not exist\n";
            return;
        }
		if (pos == 0 && start->next == NULL) // when the position to delete is zero and the list has only one element, it prevents segmenation error
		{
			start = NULL; // start=NULL indicates an empty list
		}
		else if (pos == 0) // if position to delete is the first element but list has more elements
		{
			start = start->next; // it will move the start to the next element
		}
		else
		{
			while (counter != (pos - 1)) // to move previous and after to the node we want to delete
			{
				prev = prev->next;
				counter += 1;
			}
			prev->next = prev->next->next; // mapping the next pointer of the prev node to the next pointer of the aft node which was mapping the node after the node to be deleted
		}
	}
}

void replaceall() // to replace all the elements of the linked list
{
    int len=0,i,item,pos=0;
    temp=start;
    if (start==NULL) // when the linked list is empty
    {
        cout<<"Underflow\n";
        return;
    }
    while(temp->next!=NULL) // count the number of the values
    {
        temp=temp->next;
        len++;
    }
    temp=start;
    for (i=0;i<=len;i++)
    {
        cout<<"Enter data to replace at "<<pos<<":\n";
        cin>>item; // take the input of element
        temp->roll=item; // replace the item
        temp=temp->next; // move the temp
        pos++; // increment the pos
    }
    cout<<"The new linked list is:\n";
}

int main() // main function
{
	int ch;
	while (1) // an infinite loop to display the operations to perform with an exit option
	{
		cout << "Operations on linked list:\n";
		cout << "1) Insert at rear\n";
		cout << "2) Delete\n";
		cout << "3) Display\n";
		cout << "4) Search\n";
        cout <<"5) Replace all\n";
		cout << "6) Exit\n";
		cin >> ch;

		switch (ch)
		{
		case 1:
			insertrear(); // to add element at the end calling insertrear() and display()
			display(); // display the elements of linked list
			break;
		case 2:
            int todel;
            cout<<"Enter item to delete:\n";
            cin>>todel; // take the element to delete
			del(todel); // to delete element from the list and display()
			display();
			break;
		case 3:
			display(); // to display the linked list
			break;
		case 4:
            cout<<"Enter element to search:\n";
            int s,t;
            cin>>s; // take the element to search
			t=search(s); // to search for an element in the linked list
            if(t==-1)
            {
                cout<<"Not found\n";
            }
            else
            {
                cout<<"Element found at:"<<t<<"\n"; // display the position of the element
            }
			break;
        case 5:
            replaceall(); // replace all the elements
            display(); // display the elements of linked list
            break;
		case 6:
			exit(0); // to exit from the program
		default:
			cout << "Wrong choice\n";
			break;
		}
	}
	return 0;
}
