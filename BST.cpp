#include<iostream>
using namespace std;
struct node{									//structure node
	int data;									//data of node
	node *left;									//left pointer of node
	node *right;								//right pointer of node
}*root=NULL;									//root pointer
void addnode(node *nroot, int data){			//adding a node
	if (nroot->data==data){						//if data in tree tree exists
		cout<<"Data exists\n";
	}
	else{										//else
		if (nroot->data>data){					//if a node is greater it becomes parent node and child goes to left
			if (nroot->left!=NULL){				//if left is not empty or NULL
				addnode(nroot->left, data);		//adding a node to left
			}
			else{								//if empty
				nroot->left=new node;			//create a node
				(nroot->left)->left=NULL;		//pointer of right and left points to NULL
				(nroot->left)->data=data;		//store data
				(nroot->left)->right=NULL;
				cout<<"Data inserted on left\n";
			}
		}
		else {									//if node is smaller then child goes to right
			if (nroot->right!=NULL){			//if right is not empty
				addnode(nroot->right, data);	//adding a node to right
			}
			else{
				nroot->right=new node;			//adding a new node
				(nroot->right)->left=NULL;		//left and right points to NULL
				(nroot->right)->data=data;		//store data
				(nroot->right)->right=NULL;
				cout<<"Data inserted on right\n";
			}
		}
	}
}
void preorder(node *nroot){						//preorder(root,left,right)
	if (nroot==NULL)							//if root is NULL
		return;
	cout<<nroot->data<<" ";						//print data
	preorder(nroot->left);						//go to left subtree
	preorder(nroot->right);						//go to right subtree
}
void postorder(node *nroot){					//postorder(left,right,root)
	if (nroot==NULL)
		return ;
	postorder(nroot->left);						//go to left subtree
	postorder(nroot->right);					//go to right subtree
	cout<<nroot->data<<" ";						//print data
}
void inorder(node *nroot){						//inorder(left,root,right)
	if (nroot == NULL)
		return ;
	inorder(nroot->left);						//go to left subtree
	cout<<nroot->data<<" ";						//print data
	inorder(nroot->right);						//go to right subtree
}
node* search(node *nroot, int data){			//searching a data
	if (nroot->data==data){						//if found return root
		return nroot;
	}
	else{
		if (nroot->data>data){					//if parent is greater
			if (nroot->left!=NULL)				//go left
				return search(nroot->left, data);//search left subtree
		}
		else{									//if parent is smaller
			if (nroot->right!=NULL)				//go right
				return search(nroot->right, data);//search right subtree
		}
	}
	return NULL;
}
int lowestfromrightsubtree(node *nroot){		//finding lowest from right subtree
	int minvalue=nroot->data;
	while (nroot->left!=NULL){
		minvalue=(nroot->left)->data;
		nroot=nroot->left;
	}
	return minvalue;
}
node* deletenode(node *nroot, int data){		//deleting a node
	if (nroot==NULL)
		return nroot;
	if (nroot->data>data){						//if parent is greater
		nroot->left=deletenode(nroot->left, data);//go to left subtree
	}
	else if(nroot->data<data){					//if parent is smaller
		nroot->right=deletenode(nroot->right, data);//go to right subtree
	}
	else{										//if 1 child is there
		if (nroot->left==NULL){					//if left node is NULL
			return nroot->right;				//rteurn right child
		}
		else if(nroot->right==NULL){			//if right child is not there
			return nroot->left;					//return left child
		}
		nroot->data=lowestfromrightsubtree(nroot->right);
		nroot->right=deletenode(nroot->right, nroot->data);
	}
	return nroot;
}
int main(){
	int ch, data;
	while (1){
		cout<<"BST operations:\n";
		cout<<"1) Insert data\n";
		cout<<"2) Inorder\n";
		cout<<"3) Preorder\n";
		cout<<"4) Postorder\n";
		cout<<"5) Search\n";
		cout<<"6) Delete\n";
		cout<<"7) Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter data\n";
				cin>>data;
				if (root==NULL){
					root = new node;
					root->data=data;
					root->left=NULL;
					root->right=NULL;
					cout<<"Root added\n";
				}
				else{
					addnode(root,data);
				}
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				cout<<"Enter data you want to search:\n";
				cin>>data;
				node *temp;
				temp=search(root, data);
				if (temp!=NULL){
					cout<<"Data found\n";
				}
				else{
					cout<<"Data not found\n";
				}
				break;
			case 6:
				cout<<"Enter element to delete:\n";
				cin>>data;
				deletenode(root,data);
				break;
			case 7:
				exit(0);
			default:
				break;
		}
	}
	return 0;
}