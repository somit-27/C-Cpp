#include<iostream>
using namespace std;
class matrix{
    int r,c;
    int mat[10][10];
    public:
        void get(){
            cout<<"ENter row and column"<<endl;
            cin>>r>>c;
            int i,j;
            cout<<"Enter elements:";
            for(i=0;i<r;i++){
                for(j=0;j<c;j++){
                    cin>>mat[i][j];
                }
            }
        }
        matrix operator + (matrix const &ma){
            matrix res;
            int i,j;
            for(i=0;i<r;i++){
                for(j=0;j<c;j++){
                    res.mat[i][j]=ma.mat[i][j]+mat[i][j];
                    cout<<res.mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        matrix operator - (matrix const &ma){
            matrix res;
            int i,j;
            for(i=0;i<r;i++){
                for(j=0;j<c;j++){
                    res.mat[i][j]=ma.mat[i][j]-mat[i][j];
                    cout<<res.mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        matrix operator * (matrix const &ma){
            matrix res;
            int i,j;
            for(i=0;i<r;i++){
                for(j=0;j<c;j++){
                    res.mat[i][j]=ma.mat[i][j]*mat[i][j];
                    cout<<res.mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};
int main(){
    int val;
    cin>>val;
    if(val==1){
        matrix p,q,r;
        p.get();
        q.get();
        r=p+q;
    }
    else if(val==2){
        matrix p,q,r;
        p.get();
        q.get();
        r=p-q;
    }
    else if(val==3){
        matrix p,q,r;
        p.get();
        q.get();
        r=p*q;
    }
    else{
        exit(0);
    }
return 0;
}