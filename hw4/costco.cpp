#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

struct node{
    string member;
    struct node *next;
};

node* cingroupmembers();
int findwhichgroup(string, node**, int);
node* enqueue_add(string, node*);
node* enqueue_cut(string, node*, node*);

int main(){
    int numOfGroups;
    cin>>numOfGroups;
    node *groupMembers[numOfGroups];
    for(int i=0;i<numOfGroups;i++)groupMembers[i] = cingroupmembers();

    node *inQueue = new node;
    inQueue->next = NULL;
    node *outQueue = new node;
    outQueue->next = NULL;

    while(!cin.eof()){
        string command;
        cin>>command;
        if(command == "ENQUEUE"){
            string person;
            cin>>person;
            int groupofperson = findwhichgroup(person, groupMembers, numOfGroups);
            if(groupofperson == -1) inQueue = enqueue_add(person, inQueue);
            else inQueue = enqueue_cut(person, groupMembers[groupofperson], inQueue);
        }
        else if(command == "DEQUEUE"){
            if(inQueue->next!=NULL){
                node* it = inQueue->next;
                inQueue->next = inQueue->next->next;
                node* last = outQueue;
                while(last->next!=NULL) last=last->next;
                last->next = it;
                last->next->next = NULL;
            }
        }
    }

    node* th = outQueue;
    while(th->next!=NULL){
        cout<<th->next->member<<endl;
        th=th->next;
    }

    return 0;
}

node* cingroupmembers(){
    int num;
    cin>>num;
    node *head, *cur = NULL;
    for(int i=0;i<num;i++){
        head = new node;
        cin>>head->member;
        head->next = cur;
        cur = head;
    }
    return head;
}

int findwhichgroup(string person, node** groupMembers, int numOfGroups){
    for(int i=0;i<numOfGroups;i++){
        node *temp = groupMembers[i];
        while(temp!=NULL){
            if(person == temp->member)return i;
            else temp = temp->next;
        }
    }
    return -1;
}

node* enqueue_add(string person, node *head){
    node* last = head;
    while(last->next!=NULL)last = last->next;
    last->next = new node;
    last = last->next;
    last->member = person;
    last->next = NULL;
    return head;
}

node* enqueue_cut(string person, node *groupMembers, node *head){
    node *know = head, *gmember = groupMembers;
    int found = 0;
    while(know->next!=NULL){
        while(gmember!=NULL){
            if(know->next->member == gmember->member){
                node *newnode = new node;
                newnode->member = person;
                newnode->next = know->next;
                know->next = newnode;
                found = 1;
                break;
            }
            else gmember = gmember->next;
        }
        if(found == 1) break;
        else know = know->next;
        gmember = groupMembers;
    }
    if(found==0) return enqueue_add(person, head);
    return head;
}
