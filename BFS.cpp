#include<iostream>
using namespace std;
class bfs								//creating a class BFS
{
	private:
	int a[10][10];						//defining adjacency matrix
	int n,*visit;						//define n for number of nodes and visit to track whether node is visited or not
	public:
		bfs();							//constructor to initialize matrix elements to 0;
		void read();					//function to take input 
		void searchfrom();				//function to print all nodes from string node
		void print();					//function to print the starting node
};
bfs::bfs(){								//default constructor
	cout<<"Breadth first Search"<<endl;	
	cout<<"Enter the number of nodes in graph:";//ouput to enter number of nodes
	cin>>n;								//input of n
	visit=new int[n];					//creating a space for integer and storing address in visit
	for(int i=0;i<=n;i++){				//for loop to traverse from 1st column to last column
		visit[i]=0;						//initialize all elements to 0 as they are not visited
		for(int j=0;j<=n;j++){			//from 1 to n
			a[i][j]=0;					//intitialize matrix to 0
		}
	}
}
void bfs::read(){						//to read the elements of matrix 
	for(int i=1;i<n;i++){				//using for loop from 1 to n for rows
		for(int j=1;j<=n;j++){			//using for loop from 1 to n for columns
			if(i!=j){					//ignoring loops on itself i.e. not diagonal elements
			cout<<"\n Enter the valuesof:"<<i<<","<<j<<"->";
			cin>>a[i][j];				//taking input of 0 or 1 depending on connection of nodes in graph
			}
		}
	}
}
void bfs::print()						//to print the graph in order
{
	cout<<"\n Nodes are visited in the order:"<<endl;
	for(int i=1;i<=n;i++){				//using for loop from 1 to n
		if(visit[i]==0){				//if visit of that node is 0
		cout<<i<<"->";					//print that node
		visit[i]=1;						//now initialize visit to 1
		searchfrom();					//go to searchfrom function to check the thr further nodes
		}
	}
}
void bfs::searchfrom(){					//to print nodes which will be next visited
	for(int k=1;k<=n;k++){				//using for loop from 1 to n 
		for(int i=k+1;i<=n;i++){		//using another for loop to check which element is next connected
			if(visit[i]==0 && a[k][i]!=0){//if it is not visited before and it is conneccted to the node
				cout<<i<<"->";			//print the node
				visit[i]=1;				//initialize visit to 1 for that node
			}
		}
	}
}
int main()
	{
	bfs b1;								//creating object of class
	b1.read();							//to read all matrix values
	b1.print();							//to print the nodes in BFS order
}
