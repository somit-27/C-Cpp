#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n){                       //Bubble sort function        
    int i,j;                                            //initialize i and j for loops
    for(i=0;i<n;i++){                                   //i loop from 0 to n to traverse n times whole array
        for(j=0;j<n-i-1;j++){                           //j loop from 0 to n-i-1 because the greatest element will always be present at last so no need for 
            if(arr[j]>arr[j+1]){                        //if element at left is greater than that to its right then
                int temp;                               //initialize temporary for swapping
                temp=arr[j];                            //swapping elements
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void merge(int arr[],int left, int mid, int right,int n){//merge function for merge sort
    int temp[n],i=left,j=mid+1,k=left;                  //initialize temp array and i,j,k as left,mid and left
    while(i<=mid&&j<=right){                            //while i and j can traverse through their arrays
        if(arr[i]<=arr[j]){                             //if element at i is smaller or equal to at that of j then
            temp[k]=arr[i];                             //smaller element will be put to temp array in this case of 1st array
            i++;                                        //i will get incremented
        }
        else{                                           //if it is opposite to that condition
            temp[k]=arr[j];                             //then smaller element is put to temp array in this case os 2nd array
            j++;                                        //increment j
        }
        k++;                                            //k will always get incremented after storing any value from above 2 cases
    }
    if(i>mid){                                          //now if 1st element is finished and elements remain in 2nd array
        while(j<=right){                                //while loop to traverse through whole 2nd array
            temp[k]=arr[j];                             //storing values continuously in temp array
            j++;                                        //increment j
            k++;                                        //increment k
        }
    }
    else{                                               //now if 2nd element is finished and elements remain in 1st array
        while(i<=mid){                                  //while loop to traverse through whole 1st array
            temp[k]=arr[i];                             //storing values continuously in temp array
            i++;                                        //increment i
            k++;                                        //increment k
        }
    }
    for(k=left;k<=right;k++){
        arr[k]=temp[k];
    }
}
void mergeSort(int arr[],int left,int right,int n){     //merge sort function
    if(left<right){                                     //if left is smaller than right i.e. until 2 elements are present in array
        int mid=(left+right)/2;                         //initialize mid 
        mergeSort(arr,left,mid,n);                      //form 1st array of left to mid elements
        mergeSort(arr,mid+1,right,n);                   //form 2nd array of mid+1 to right elements
        merge(arr,left,mid,right,n);                    //merge the 2 array using merge function
    }
}
int breaking(int arr[],int left, int right){            //breaking the array in 2 by placing pivot in the middle and small elemts to its left and greater at right
    int pivot=arr[left];                                //intitialize pivot as first element of that array
    int start=left,end=right;                           //initialize start and end as left and right
    int temp;                                           //intitialize temp element for swapping
    while(start<end){                                   //while loop until start as behind end
        while(arr[start]<=pivot){                       //while loop until small elements than pivot are present from start then
            start++;                                    //increment start
        }
        while(arr[end]>pivot){                          //while loop until large elemnets than pivot are present from end then
            end--;                                      //decrement end
        }
        if(start<end){                                  //now if start is behind end and above 2 while loops are executed then
            temp=arr[start];                            //swap the elements at start and end as they contain large and small elements respectively
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    if(start>end){                                      //but if start is now ahead of end the small elements are now present to the left side of array and vice verse
        temp=arr[left];                                 //swapping the pivot element of the particular array and the element at end
        arr[left]=arr[end];
        arr[end]=temp;
    }
    return end;                                         //returning end so that we can know the ending of 1st array and starting of 2nd array 
}
void quickSort(int arr[],int left,int right){           //Quick Sort Function
    int pos;                                            //initialize pos as breaking function returns end value
    if(left<right){                                     //if left is smaller thamn right
        pos=breaking(arr,left,right);                   //use breaking function to find where pivot is element is now stored
        quickSort(arr,left,pos-1);                      //quick sort for array to then left of pivot element
        quickSort(arr,pos+1,right);                     //quick sort for array to the right of pivot element        
    }
}
void display(int arr[],int n){
    int i;
    cout<<"The sorted array is:"<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int i,n;
    cout<<"Enter number of elements:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements of array:"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Choose the sorting method from the following:"<<endl;
    cout<<"1.Bubble Sort"<<endl;
    cout<<"2.Merge Sort"<<endl;
    cout<<"3.Quick Sort"<<endl;
    cout<<"Enter your choice"<<endl;
    int ch;
    cin>>ch;
    switch(ch){
        case 1:
        bubbleSort(arr,n);
        display(arr,n);
        break;
        case 2:
        mergeSort(arr,0,n-1,n);
        display(arr,n);
        break;
        case 3:
        quickSort(arr,0,n-1);
        display(arr,n);
        break;
        default:
        cout<<"Wrong choice";
        break;
    }
}