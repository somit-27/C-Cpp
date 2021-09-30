// Verification of circular prime number
// A circular prime number is a prime number 'p' with a property that all the numbers got by cyclically permuting the digits of 'p', are also a prime number.
// A number is said to be a prime if it has no factors other than the number 1 and itself. 19937 is a circular prime number, as all the numbers obtained by cyclically permuting the number 19937 : 99371, 93719,37199,71993,19937 are all prime.
// Develop an algorithm and write a C program to check if the given number is a circular prime or not.
// Input Format
// A number
// Output Format
// Print Circular prime or Not circular prime

// #include<iostream>
// #include<cmath>
// using namespace std;
// bool prime(int n){
//     int i=2;
//     while(i!=n){
//         if(n%i==0)
//         return false;
//         i++;
//     }
//     return true;
// }
// int main(){
//     int i,n,temp,count1=0,count2=0;
//     cin>>n;
//     temp=n;
//     while(temp!=0){
//         count1++;
//         temp=temp/10;
//     }
//     for(i=0;i<count1;i++){
//         if(prime(n)){
//             count2++;
//         }
//         int x;
//         x=n%10;
//         n=n/10;
//         n=pow(10,count1-1)*x+n;
//     }
//     if(count2==count1)
//         cout<<"Circular prime";
//     else
//     cout<<"Not circular prime";
// }
//************************************************************************************************************************************************************

// Identify machines in same local network
// Numeric addresses for computers on the international network, 'Internet' has four parts, separated by periods, of the form   xxx.yyy.zzz.mmm    where  xxx ,  yyy ,  zzz , and  mmm  are positive integers. Locally, computers are usually known by a nickname as well.
// Sample Data 
// IP address       Name
// 111.22.3.44        platte 
// 555.66.7.88        wabash 
// 111.22.5.66        green 
// 0.0.0.0                none
// A pair of computers are said to be in same locality when the first two components of the addresses are same. Given the details of some computers, design an algorithm and write a C program to display a list of messages identifying each pair of computers from the same locality. In the messages, the computers should be identified by their nicknames. In this example, the message to be displayed will be Machines platte and green are on the same local network. For example, given IP address and nick name of machines as follows:
// 101.33.2.1              Atlas
// 101.33.56.80          Horizon
// 101.43.45.74          Pluto
// Print 'Machines Atlas and Horizon are on the same local network'.
// Input Format
// Number of computers 'n'
// IP address of the computer1 as a String
// Nick names of the computer1 as a String
// IP address of the computer2 as a String
// Nick names of the computer2 as a String
// ....
// IP address of the computer n as a String
// Nick names of the computer n as a String
// Output Format
// For each pair of machines in the same local network, print:
// Machines A and B are on the same local network (A and B are names of the respective machines)

// #include<iostream>
// #include<string.h>
// using namespace std;
// class ip{
//     public:
//         string ip;
//         string name;
// };
// int main(){
//     int n;
//     cin>>n;
//     ip a[n];
//     int i,j;
//     for(i=0;i<n;i++){
//         cin>>a[i].ip;
//         cin>>a[i].name;
//     }
//     for(i=0;i<n;i++){
//         for(j=i+1;j<n;j++){
//             string s1,s2,s3,s4;
//             int k=0,l;
//             while(a[i].ip[k]!='.'){
//                 k++;
//             }
//             s1=a[i].ip.substr(0,k);
//             l=++k;
//             k=0;
//             while(a[i].ip[k]!='.'){
//                 k++;
//             }
//             s2=a[i].ip.substr(l,k-1);
//             k=0;
//             while(a[j].ip[k]!='.'){
//                 k++;
//             }
//             s3=a[j].ip.substr(0,k);
//             l=++k;
//             k=0;
//             while(a[j].ip[k]!='.'){
//                 k++;
//             }
//             s4=a[j].ip.substr(l,k-1);
//             if((s1==s3)&&(s2==s4)){
//                 cout<<"Machines "<<a[i].name<<" and "<<a[j].name<<" are on the same local network"<<endl;
//             }
//         }
//     }
// }

// **********************************************************************************************************************

// Automatic vending machine
// An automatic vending machine has many snack items arranged in its shelves. Each item has an item code and a cost. A user can enter the amount and key-in the item code.
// If the itemcode matches an entry in the item list and amount entered by user is less than cost of the item, then the item will be dispensed. Develop an algorithm and
// write a C++ code to print name of the item if the amount entered is greater than the cost of the item and item code is valid. If the amount is less than the cost of 
//the item then throw a double exception, if the item code entered is wrong then throw a integer exception and when the item entered is not in stock throw a string 
//exception. Print appropriate messages such as “Insufficient amount”, “Wrong item code” or “Less stock”.
// Input Format:
// Enter the number of items in the vending machine
// Itemcode-1
// Cost of item1
// stock in hand item1
// Itemcode-2
// Cost of item2
// stock in hand item2
// …
// Itemcode-n
// Cost of item1
// stock in hand item3
// Item code entered by user
// Cost entered by user
// Output Format:
// Print either item name or “Insufficient amount” or “Wrong item code” or “Less Stock”
// Boundary Conditions:
// Number of Item  >1

// #include<iostream>
// using namespace std;
// class avm{
//     public:
//     int code;
//     int cost;
//     int stock;
//     void get_data(){
//         cin>>code;
//         cin>>cost;
//         cin>>stock;
//     }
// };
// int main(){
//     int i,n,ic,co,index;
//     cin>>n;
//     avm a[n];
//     for(i=0;i<n;i++){
//         a[i].get_data();
//         //cout<<a[i].code<<endl;
//     }
//     cin>>ic>>co;
//     int flag=0;
//     for(i=0;i<n;i++){
//         if(a[i].code==ic){
//             flag=1;
//             index=i;
//             break;
//         }
//     }
//     try{
//         if(flag==1){
//             if(a[i].stock>=1){
//                 if(co>a[i].cost){
//                     cout<<a[index].code<<endl;
//                 }
//                 else{
//                     throw 1.1;
//                 }
//             }
//             else{
//                 throw "stock kam hai";
//             }
//         }
//         else{
//             throw flag;
//         }
//     }
//     catch(int flag){
//         cout<<"Wrong item code"<<endl;
//     }
//     catch(string c){
//         cout<<"Less stock"<<endl;
//     }
//     catch(double x){
//         cout<<"Insufficient amount";
//     }
// }
// ******************************************************

// Chess, Carrom and Scrabble Players
// Each student in a class of 'n' plays at least one indoor game chess, carrom and scrabble. Given three list of names of students who play chess, scrabble and carrom, develop an algorithm and write a C++ code to find the students who can
// (i) Play chess and carrom
// (ii) Chess, carrom but not scrabble
// Understand the template code and implement the member functions of the class
// Input Format
// Number of students who play chess
// Name of student1 who plays chess
// Name of student2 who plays chess
// ...
// Name of student-n who plays scrabble
// Number of students who play scrabble
// Name of student1 who plays scrabble
// Name of student2 who plays scrabble
// ...
// Name of student-n who plays scrabble
// Number of students who play carrom
// Name of student1 who plays carrom
// Name of student2 who plays carrom
// ...
// Name of student-n who plays carrom
// Output Format
// Anchor Name of students who play chess and carrom. order the names as given in the chess input list . separate names by a comma
// Name of students who play chess and carrom but not scrabble. Order the names as given in the chess input list. separate names by a comma
// Boundary Conditions
// Number of students in class will not be more than 30
// Length of name of students in class will not be more than 20
// Assume that none of the set will become empty

// #include<iostream>
// #include<cstring>
// using namespace std;
// class set
// {
// 	int num_Of_Ele;
// 	char names[30][20];
// 	public:
// 	void get();
// 	void print()const;
// 	set intersection(set&);
// 	set difference(set&);
// };
// set a;
// void set::get(){
//     cin>>num_Of_Ele;
//     int i;
//     for(i=0;i<num_Of_Ele;i++){
//         cin>>names[i];
//     }
// }
// set set::intersection(set& c){
//     int i,j,k=0;
//     for(i=0;i<num_Of_Ele;i++){
//         for(j=0;j<c.num_Of_Ele;j++){
//             if(strcmp(names[i],c.names[j])==0){
//                 strcpy(a.names[k],names[i]);
//                 k++;
//             }
//         }
//     }
//     a.num_Of_Ele=k;
//     return a;
// }
// set set::difference(set& c){
//     set a2;
//     int i,j,k=0,flag=0;
//     for(i=0;i<a.num_Of_Ele;i++){
//         flag=0;
//         for(j=0;j<c.num_Of_Ele;j++){
//             if(strcmp(a.names[i],c.names[j])==0){
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==0){
//             strcpy(a2.names[k],a.names[i]);
//             k++;
//         }
//     }
//     a2.num_Of_Ele=k;
//     return a2;
// }
// void set::print()const{
//     int i;
//     for(i=0;i<num_Of_Ele;i++){
//         if(i!=num_Of_Ele-1){
//             cout<<names[i]<<",";
//         }
//         else{
//             cout<<names[i]<<endl;
//         }
//     }
// }
// int main()
// {
// 	set chess, carrom,scrabble;
// 	chess.get();
// 	carrom.get();
// 	scrabble.get();
// 	set inter = chess.intersection(carrom);
// 	inter.print();
// 	set diff = inter.difference(scrabble);
// 	diff.print();
// 	return 0;
// }
//****************************************************************************************************************************************
