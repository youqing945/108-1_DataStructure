#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int n,N;

void powerset(int x, int bit[],int ans[],int no1[]) {
  if(x == N) {
    for (int i = 0; i < N; i++){
            ans[n*N+i]=bit[i];
            if(bit[i]>0) no1[n]++;
    }
    n++;
    return;
  }

  bit[x] = 1;
  powerset(x+1, bit, ans, no1);
  bit[x] = 0;
  powerset(x+1, bit, ans, no1);
}

int main(){
    string input[10];
    n=0;
    N=0;

    while(!cin.eof()){
        cin >> input[N];
        N++;
        if(cin.get()!=10);
        else{
            n = pow(2,N);
            int bit[N], ans[n*N], no1[n]={0};
            n=0;
            powerset(0, bit, ans, no1);

            cout<<"{}";
            for(int i=1;i<=N;i++){
                for(int j=0;j<pow(2,N);j++){
                    if(no1[j]==i){
                        cout<<" {";
                        for(int k=0;k<N;k++){
                            if(ans[N*j+k]==1){
                                cout<<input[k];
                                int flag = 0;
                                for(int l=k+1;l<N;l++)
                                    if(ans[N*j+l]==1){
                                        cout<<" "<<input[l];
                                        flag=1;
                                    }
                                if(flag>0) break;
                            }
                        }
                        cout<<"}";
                    }
                }
            }

            //============
            cout<<"\n";
            N=0;
            n=0;
            string input[10];
        }
    }
    return 0;
}
