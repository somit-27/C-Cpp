#include<iostream>
using namespace std;

int stack[10];
int topl=-1;
int topr=10;

void pushl()
{
	int data;
	if (topl+1==topr)
	{
		cout<<"Overflow\n";
	}
	else
	{
		cout<<"Enter data:\n";
		cin>>data;
		stack[++topl]=data;
	}
}

void pushr()
{
	int data;
	if (topr==topl+1)
	{
		cout<<"Overflow\n";
	}
	else
	{
		cout<<"Enter data:\n";
		cin>>data;
		stack[--topr]=data;
	}
}

void popl()
{
	if (topl==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{
		cout<<"Popped element: "<<stack[topl]<<"\n";
		topl--;
	}
}

void popr()
{
	if (topr==10)
	{
		cout<<"Underflow\n";
	}
	else
	{
		cout<<"Popped element: "<<stack[topr]<<"\n";
		topr++;
	}
}

void display()
{
	int i;
	for (i=0;i<=topl;i++)
	{
		cout<<stack[i]<<"\t";
	}
	for (i=topl+1;i<topr;i++)
	{
		cout<<"-\t";
	}
	for (i=topr;i<10;i++)
	{
		cout<<stack[i]<<"\t";
	}
	cout<<"\n";
}

int main()
{
	int ch;
	int side;
	while(1)
	{
		cout<<"Double ended stack:\n";
		cout<<"1) Push\n";
		cout<<"2) Pop\n";
		cout<<"3) Display\n";
		cout<<"4) Exit\n";
		
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Push in which side? left/right(0/1):\n";
				cin>>side;
				if (side==1)
				{
					pushl();
					display();
				}
				else if (side==2)
				{
					pushr();
					display();
				}
				break;
			case 2:
				cout<<"Pop on which side? l/r:\n";
				cin>>side;
				if (side==1)
				{
					popl();
					display();
				}
				else if (side==2)
				{
					popr();
					display();
				}
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"Wrong choice\n";
				break;
		}
	}
	return 0;
}