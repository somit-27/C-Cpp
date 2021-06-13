#include<iostream>
#include<stdlib.h>
using namespace std;
int list[10];								//initializing list 
int last=-1;								//initializing a variable last to keep track
void insert(int value){						//inserting in list
    list[last+1]=value;						//increment last and store the value
    last++;
}
void display(){								//to display
    int i;									
    cout<<"The values in list are"<<endl;	
    for(i=0;i<=last;i++){					//using for loop from index 0 to last
        cout<<i<<"\t"<<list[i]<<endl;
    }
}
void insert_in_between(int data,int p){		//insert in between the list
    int i;	
    for(i=last;i>=p;i--){					//shofting the list from the pos p till end 1 space ahead
        list[i+1]=list[i];
    }
    list[p]=data;							//storing the data in pth position
    last++;									//incrementing last 
}
void deletion(int p){						//to delete
    int i;
    for(i=p;i<=last;i++){					//from position p to last decrementing index by 1
        list[i]=list[i+1];
    }
	last--;									//decrementing last 
}
int main()
{
	int ch;
	int loop=1;
	while (1)
	{
		cout<<"Choose any Operation from the following list:\n";
		cout<<"1) Insert\n";
		cout<<"2) Insertion in between\n";
		cout<<"3) Deletion\n";
		cout<<"4) Display\n";
		cout<<"5) Exit\n";
		cin>>ch;
		switch (ch)							//using switch case to choose between options in menu
		{
			case 1:
				int data;
				cout<<"Enter data:\n";
				cin>>data;
				insert(data);
				display();
				break;
			case 2:
				int p,d;
				cout<<"Enter position at which to enter element:\n";
				cin>>p;
				cout<<"Enter data:\n";
				cin>>d;
				insert_in_between(d,p);
				display();
				break;
			case 3:
				int y;
				cout<<"Enter position at which element is to be deleted:\n";
				cin>>y;
				deletion(y);
				display();
                break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				break;
		}
		}return 0;
}