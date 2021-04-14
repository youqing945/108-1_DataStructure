#include<iostream>
using namespace std;

int Ackerman(int m, int n){
    if(m==0) return n+1;
    if(n==0) return Ackerman(m-1, 1);
    return Ackerman(m-1, Ackerman(m, n-1));
}

int main(){
    int m, n;
    while(!cin.eof()){
            cin >> m >> n ;
            cout << Ackerman(m, n) << endl;
    }
    return 0;
}
