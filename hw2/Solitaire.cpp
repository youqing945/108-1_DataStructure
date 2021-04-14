#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int A[13];

void printA(int num){
    if(A[0]==1)cout<<"A";
    else if(A[0]==11)cout<<"J";
    else if(A[0]==12)cout<<"Q";
    else if(A[0]==13)cout<<"K";
    else cout<<A[0];
    for(int i=1;i<num;i++){
        if(A[i]==1)cout<<" A";
        else if(A[i]==11)cout<<" J";
        else if(A[i]==12)cout<<" Q";
        else if(A[i]==13)cout<<" K";
        else cout<<" "<<A[i];
    }
    cout<<endl;
}

int main(){
    srand(time(NULL));
    for(int i=0;i<13;i++){
        int isUsed;
        do{
            A[i] = rand()% 13 + 1;
            isUsed = 0;
            for(int j=0;j<i;j++){
                if(A[i]==A[j]){
                    isUsed=1;
                    break;
                }
            }
        }while(isUsed==1);
    }
    //============
    for(int i=13; i>0; i--){
        printA(i);
        while(A[0]!=i){
            int temp = A[0];
            for(int j=0;j<i-1;j++)A[j]=A[j+1];
            A[i-1] = temp;
            printA(i);
        }
        for(int j=0;j<i-1;j++)A[j]=A[j+1];
    }
    return 0;
}


