#include<iostream>
using namespace std;
#define maxsize 5
int rear1=-1, front1=-1, queue1[maxsize];
int rear2=-1, front2=-1, queue2[maxsize];
void insertion1(int ele){
  if(rear1 == maxsize-1){
		cout<<"Queue is full"<<endl;
	}
	else if(front1 == -1 && rear1 == -1){
		front1 = rear1 = 0;
		queue1[rear1] = ele;
	}else{
		rear1++;
		queue1[rear1] = ele;
	}
}
int deletion1(){
  int x;
  if(front1==-1 && rear1==-1){
		cout<<"Queue is empty"<<endl;
	}
	else if(front1 == rear1){
		x = queue1[front1];
		front1 = rear1 = -1;
	}
	else{
		x = queue1[front1];
		front1++;
	}
  return x;
}
void insertion2(int ele){
  if(rear2 == maxsize-1){
		cout<<"Queue is full"<<endl;
	}
	else if(front2 == -1 && rear2 == -1){
		front2 = rear2 = 0;
		queue2[rear2] = ele;
	}else{
		rear2++;
		queue2[rear2] = ele;
	}
}
int deletion2(){
  int x;
  if(front2==-1 && rear2==-1){
		cout<<"Queue is empty"<<endl;
	}
	else if(front2 == rear2){
		x = queue2[front2];
		front2 = rear2 = -1;
	}
	else{
		x = queue2[front2];
		front2++;
	}
  return x;
}
void push()
{
  int ele;
  cout<<"Enter the element to be inserted"<<endl;
  cin>>ele;
  if(front1==-1){
    insertion1(ele);
  }else if(front1==rear1){
    int a;
    a = deletion1();
    insertion2(a);
    insertion1(ele);
    a = deletion2();
    insertion1(a);
  }else{
    int a;
    while(front1 != -1 && rear1!=-1){
    a = deletion1();
    insertion2(a);
  }
   insertion1(ele);
   while(front2 !=-1 && rear2 != -1){
     int a;
     a = deletion2();
     insertion1(a);
   } 
  }
}
void pop()
{
  int a;
  a = deletion1();
  cout<<"The dequeued element is "<<a<<endl;
}
void display()
{
  int i;
  for(i=front1;i<=rear1;i++)
  {
    cout<<queue1[i]<<" ";
  }
  cout<<endl;
}
int main()
{
  int ch;
  while(1)
  {
    cout<<"1.Push\n2.Pop\n3.Display\n4.Exit";  
    cout<<"\nEnter your choice:"<<endl;
    cin>>ch;
    switch(ch)
    {
      case 1:
      push();
      break;
      case 2: 
      pop();
      break;
      case 3:
      display();
      break;
      case 4:
      exit(0);
    }
  }
  return 0;
}