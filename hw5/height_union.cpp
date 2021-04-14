#include<iostream>
#include<vector>
#include<string>
using namespace std;

void heightUnion(int parent[],int i,int j);
int collapsingFind(int parent[], int p);

int main(){
    //data setting
    vector<int> record_node;
    vector<int> record_parent;

    int tree_num;
    cin>>tree_num;

    int node_num[tree_num];
    for(int i=0; i<tree_num; i++){
        cin>>node_num[i];
        for(int j=0; j<node_num[i]; j++){
            int x, y;
            cin>>x>>y;
            record_node.push_back(x);
            record_parent.push_back(y);
        }
    }

    int total_node = 0;
    for(int i=0; i<tree_num; i++){
        total_node = total_node + node_num[i];
    }

    int parent[total_node];
    for(int i=0;i<total_node;i++){
        for(int j=0;j<record_node.size();j++){
            if(i==record_node[j]){
                parent[i] = record_parent[j];
                record_node.erase(record_node.begin()+j);
                record_parent.erase(record_parent.begin()+j);
                break;
            }
        }
    }

    vector<int> result;
    //read commands
    while(!cin.eof()){
        string command;
        cin>>command;
        if(command == "UNION"){
            int i, j;
            cin>>i>>j;
            heightUnion(parent, i, j);
        }
        else if(command == "FIND"){
            int p;
            cin>>p;
            result.push_back(collapsingFind(parent, p));
        }
        else if(command == "STOP"){
            break;
        }
    }

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }

    return 0;
}

void heightUnion(int parent[], int i, int j){
    if(parent[i]<0 && parent[j]<0){
        if(parent[i]>parent[j]){
            parent[i] = j;
        }
        else{
            if(parent[i]==parent[j]){
                parent[i]--;
            }
            parent[j] = i;
        }
    }
    else{
        cout<<"!command error!"<<endl;
    }
}

int collapsingFind(int parent[], int p){
    int steps = 0;

    //find the root
    int root = p;
    while(parent[root]>=0){
        root = parent[root];
        steps++;
    }

    //collapsing rule
    while(parent[p]!=root){
        int tmp = parent[p];
        parent[p]=root;
        p = tmp;
        steps++;
    }

    return steps;
}
