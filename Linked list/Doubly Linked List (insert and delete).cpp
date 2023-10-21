#include<bits/stdc++.h>
using namespace std;


// class node

class node{
    public:

    int data;
    node* next;
    node* prev;

    //  Constructor of class node
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

// Insert At Head

void insert_at_head(node* &head,int val){
    node* n=new node(val);
    n->next=head;
   if(head!= NULL)   head->prev = n;

    head = n;
}


// Insert Element At Tail

void insert_at_tail(node* &head,int val){

if(head==NULL){
        insert_at_head(head,val);
        return;
    }
    
    node* n=new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
        }

        temp->next=n;
        n->prev = temp;
}

// delete from head
void delete_tohead(node* &head){
     node* todelete = head;
     head = head->next;
     head->prev = NULL;

     delete todelete;
}

//delete from any position
void deletion (node* &head, int val){


    if(head== NULL){
        return;
    }

    if(val==1){
        delete_tohead(head);
        return;
    }


    node* temp = head;
    int count = 1;

    while(temp!= NULL && count!=val){
         temp=temp->next;
         count++;
    }
     
     temp->prev->next = temp->next;
     if(temp->next != NULL)  temp->next->prev = temp->prev; 

    delete temp;
}


// Display Element

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" "; //"->";
        temp=temp->next;
    }
    //cout<<"NULL"<<endl;
    cout<<endl;
}

int main(){
    node*  head = NULL;
     insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    display(head);

    insert_at_head(head,5);
    insert_at_head(head,6);
    display(head);

    deletion(head,4);
    display(head);

    deletion(head,1);
    display(head);

    return 0;

}


