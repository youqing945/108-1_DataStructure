#include<iostream>
using namespace std;

int main(){
    int pathnum;
    cin>>pathnum;

    int Path[pathnum][4]; //0:no. 1:i 2:j 3:time
    int Act[pathnum][4]; //0:no. 1:e 2:l 3:slack

    for(int i=0; i<pathnum; i++){
        for(int j=0; j<4; j++){
            cin>>Path[i][j];
            if(j==0) Act[i][j] = Path[i][j];
        }
    }
    //===========================

    int eventnum = 0;
    for(int i=0; i<pathnum; i++){
        if(Path[i][2]>eventnum) eventnum = Path[i][2];
    }
    eventnum++;

    int Event[eventnum][2]; //0:ee 1:le

    for(int i=0; i<eventnum; i++) {
            Event[i][0] = 0;
            Event[i][1] = 99999999;
    }

    //

    //calculate ee
    while(1>0){
        int check = 0;

        for(int i = 0; i<pathnum; i++){
            if(Event[Path[i][1]][0]+Path[i][3]>Event[Path[i][2]][0]){
                Event[Path[i][2]][0] = Event[Path[i][1]][0]+Path[i][3];
                check = 1;
            }
        }

        if(check==0) break;
    }

    Event[eventnum-1][1] = Event[eventnum-1][0];

    //calculate le
    while(1>0){
        int check = 0;

        for(int i = pathnum-1; i>=0; i--){
            if(Event[Path[i][2]][1]-Path[i][3]<Event[Path[i][1]][1]){
                Event[Path[i][1]][1] = Event[Path[i][2]][1]-Path[i][3];
                check = 1;
            }
        }

        if(check==0) break;
    }

    //calculate e(i) = ee(k) k->i->j
    //calculate l(i) = le(j) - time(i)
    //calculate slack = l(i) - e(i)
    for(int i = 0; i<pathnum; i++){
        Act[i][1] = Event[Path[i][1]][0];
        Act[i][2] = Event[Path[i][2]][1] - Path[i][3];
        Act[i][3] = Act[i][2] - Act[i][1];
    }

    //============================
    //print

    cout<<"event\tee\tle\n";
    for(int i=0; i<eventnum; i++){
        cout<<i<<"\t"<<Event[i][0]<<"\t"<<Event[i][1]<<"\n";
    }
    cout<<endl;
    cout<<"act.\te\tl\tslack\tcritical\n";
    for(int i=0; i<pathnum; i++){
        for(int j=0; j<4; j++){
            cout<<Act[i][j]<<"\t";
        }
        if(Act[i][3]==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    cout<<endl;
    for(int i=0; i<pathnum; i++){
        if(Act[i][3]==0) cout<<Act[i][0]<<" ";
    }
    cout<<endl;

    return 0;
}
