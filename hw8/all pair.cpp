#include<iostream>
using namespace std;


void printout(int p[], int pofthis, int layer);

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

    int d[v][v]; //distance
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i==j) d[i][j] = 0;
            else d[i][j] = 1000000;
        }
    }

    int p[v][v]; //parent
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++) p[i][j] = i;
    }
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
                    for(int c=0; c<v; c++){
                        if(d[c][a]<1000000&&d[c][b]>999999){
                            d[c][b] = d[c][a] + w[a][b];
                            p[c][b] = a;
                            check = 0;
                        }
                        else if(d[c][a]<1000000&&d[c][b]<1000000){
                            if(d[c][b]>d[c][a]+w[a][b]){
                                d[c][b] = d[c][a] + w[a][b];
                                p[c][b] = a;
                                check = 0;
                            }
                        }
                    }
                }
            }
        }
        //if(check == 1) break;
    }
    ///////////////////////////
    ///////////////////////////
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i!=j){
                if(d[i][j]!=1000000){
                    printout(p[i], j, i);
                    cout<<" "<<d[i][j];
                }
                else cout<<"Impossible";
                cout<<endl;
            }
        }
    }

    return 0;
}

void printout(int p[], int pofthis, int layer){
    if(p[pofthis] == layer){
        cout<<layer<<","<<pofthis;
        return;
    }
    else{
        printout(p, p[pofthis], layer);
        cout<<","<<pofthis;
    }
}
