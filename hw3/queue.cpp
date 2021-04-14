#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int numOfGroups;
    cin>>numOfGroups;
    int numOfMembers[numOfGroups];
    vector<vector<string> > groupMembers;

    for(int i=0;i<numOfGroups;i++){
        cin>>numOfMembers[i];
        vector<string> tempvec;
        for(int j=0;j<numOfMembers[i];j++){
            string temp;
            cin>>temp;
            tempvec.push_back(temp);
        }
        groupMembers.push_back(tempvec);
    }

    vector<string> inQueue;
    vector<string> outQueue;

    while(!cin.eof()){
        string command;
        cin>>command;
        if(command == "ENQUEUE"){
            string person;
            cin>>person;
            int groupOfPerson = -1;
            for(int i=0;i<numOfGroups;i++){
                for(int j=0;j<groupMembers[i].size();j++){
                    if(person == groupMembers[i][j]){
                        groupOfPerson = i;
                        break;
                    }
                }
                if(groupOfPerson != -1) break;
            }
            if(groupOfPerson == -1) inQueue.push_back(person);
            else{
                int foundMember = 0;
                for(int i=0;i<inQueue.size();i++){
                    for(int j=0;j<groupMembers[groupOfPerson].size();j++){
                        if(inQueue[i]==groupMembers[groupOfPerson][j]){
                            foundMember = 1;
                            inQueue.insert(inQueue.begin()+i, person);
                            break;
                        }
                    }
                    if(foundMember == 1)break;
                }
                if(foundMember == 0)inQueue.push_back(person);
            }
        }
        else if(command == "DEQUEUE"){
            if(inQueue.size()>0){
                outQueue.push_back(inQueue[0]);
                inQueue.erase(inQueue.begin());
            }
        }
    }

    for(int i=0;i<outQueue.size();i++) cout<<outQueue[i]<<endl;
    return 0;
}
