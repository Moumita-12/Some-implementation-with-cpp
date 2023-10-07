#include<bits/stdc++.h>
using namespace std;


// class node

class node{
    public:
    int data;
    node* next;

    //  Constructor of class node
    node(int val){
        data=val;
        next=NULL;

    }
};

// Insert At Head

void insert_at_head(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}


// Insert Element At Tail

void insert_at_tail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        }
        temp->next=n;
}

// Display Element

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


// Searching any element

bool Search(node* head,int key){
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==key){
          return true;

        }
        temp=temp->next;  
  }
  return false;
  
}

int main(){
    
    node* head =NULL;
    insert_at_tail(head,11);
    insert_at_tail(head,19);
    insert_at_tail(head,21);
    display(head);

    insert_at_head(head,9);
    display(head);
    
    cout<<Search(head,9)<<endl;
    cout<<Search(head,8)<<endl;

    return 0;
}
