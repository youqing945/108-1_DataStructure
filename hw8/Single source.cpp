#include<iostream>
using namespace std;

void printout(int p[], int pofthis);

int main(){
    int v;
    cin>>v;
    //
    int w[v][v]; //weight
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            w[i][j] = -1;
        }
    }
    int d[v]; //distance
    d[0] = 0;
    for(int i=1; i<v; i++) d[i] = 1000000;
    int p[v]; //parent
    for(int i=0; i<v; i++) p[i] = 0;
    //
    int time;
    cin>>time;
    for(int i=0; i<time; i++){
        int a, b, d;
        cin>>a>>b>>d;
        w[a][b] = d;
    }

    ////////////////////////
    //calculate
    for(int i = 0; i<v-1; i++){
        int check = 1;

        for(int a=0; a<v; a++){
            for(int b=0; b<v; b++){
                if(w[a][b]!=-1){
                if(d[a]<1000000&&d[b]>999999){
                    d[b] = d[a] + w[a][b];
                    p[b] = a;
                    check = 0;
                }
                else if(d[a]<1000000&&d[b]<1000000){
                    if(d[b]>d[a]+w[a][b]){
                        d[b] = d[a] + w[a][b];
                        p[b] = a;
                        check = 0;
                    }
                }
            }
            }
        }
        //if(check == 1) break;
    }
    ///////////////////////////
    ///////////////////////////

    for(int i=1; i<v; i++){
        if(d[i]!=1000000){
            printout(p, i);
            cout<<" "<<d[i];
        }
        else cout<<"Impossible";
        cout<<endl;
    }

    return 0;
}

void printout(int p[], int pofthis){
    if(p[pofthis] == 0){
        cout<<"0,"<<pofthis;
        return;
    }
    else{
        printout(p, p[pofthis]);
        cout<<","<<pofthis;
    }
}
