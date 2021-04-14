#include<iostream>
using namespace std;
int list[10];
int last=-1;
void insert(int value){
    list[last+1]=value;
    last++;
}
void display(){
    int i;
    cout<<"The values in list are"<<endl;
    for(i=0;i<=last;i++){
        cout<<i<<"\t"<<list[i]<<endl;
    }
}
void insert_in_between(int data,int p){
    int i;
    for(i=last;i>=p;i--){
        list[i+1]=list[i];
    }
    list[p]=data;
    last++;
}
void deletion(int p){
    int i;
    for(i=p;i<=last;i++){
        list[i]=list[i+1];
    }
	last--;
}
int main()
{
	int ch;
	int loop=1;
	while (loop==1)
	{
		cout<<"Choose any Operation from the following list:\n";
		cout<<"1) Insert\n";
		cout<<"2) Insertion in between\n";
		cout<<"3) Deletion\n";
		cout<<"4) Display\n";
		cin>>ch;
		switch (ch)
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
			default:
				break;
		}
		cout<<"\nTo perform again press 1\n";
		cin>>loop;}return 0;
}