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

void delete_tohead(node* &head){
     node* todelete = head;
     head = head->next;

     delete todelete;
}

void deletion(node* &head, int val){


    if(head== NULL){
        return;
    }

    if(head->next == NULL){
        delete_tohead(head);
        return;
    }


    node* temp = head;

    //cout<<temp->data<<"-----";

    while(temp->next->data!= val){
         temp=temp->next;
    }
     

    // node* todelete = temp->next;
     // cout<<temp->data<<"-----";
    temp->next = temp->next->next; 

    //delete todelete;
}

//Reverse K Nodes in a Linked List using iteration method
node* reversek(node* &head, int k)
{
    node* prevptr = NULL;
    node* curptr= head;
    node* nextptr;

    int count = 0;
    while(curptr!=NULL && count<k){
        nextptr = curptr->next;
        curptr->next = prevptr;

        prevptr = curptr;
        curptr = nextptr;

        count++;


    }


    if(nextptr!=NULL)   head->next = reversek(nextptr,k);

    return prevptr;
}








int main(){
    
    node* head =NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    display(head);

    int k=2;
    node* newhead = reversek(head,k);
    display(newhead); 

    return 0;
}
