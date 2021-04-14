#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node{
    int value;
    struct node *next;
};

node *makelist();
void printlist(node*);
node *cal(node*, int);

int main(){
    srand(time(NULL));
    node *lis = makelist();
    printlist(lis);
    for(int i=13;i>0;i--){
        lis = cal(lis, i);
    }
    return 0;
}

node *makelist(){
    int check[14] = {0};
    node *head = new node;
    node *tag = head, *cur;
    head->value = rand()%13+1;
    check[head->value]++;
    for(int i=0;i<12;i++){
        cur = new node;
        do{
            cur->value = rand()%13+1;
        }while(check[cur->value]>0);
        check[cur->value]++;
        cur->next = NULL;
        tag->next = cur;
        tag = tag->next;
    }
    return head;
}

void printlist(node *head){
    if(head!=NULL){
        if(head->value==1) cout<<"A";
        else if(head->value==11) cout<<"J";
        else if(head->value==12) cout<<"Q";
        else if(head->value==13) cout<<"K";
        else cout<<head->value;
        head = head->next;
    }
    while(head!=NULL){
        if(head->value==1) cout<<" "<<"A";
        else if(head->value==11) cout<<" "<<"J";
        else if(head->value==12) cout<<" "<<"Q";
        else if(head->value==13) cout<<" "<<"K";
        else cout<<" "<<head->value;
        head = head->next;
    }
    cout<<endl;
}

node *cal(node*head, int num){
    node *tag = head;
    head = head->next;
    if(tag->value!=num){
        node *temp = head;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = tag;
        tag->next = NULL;
        printlist(head);
        return cal(head, num);
    }
    else{
        delete tag;
        printlist(head);
        return head;
    }
}
