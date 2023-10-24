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

//find length of linked list
int length(node* head){
    int l = 0;
    node* temp = head;
    while(temp!= NULL){
        l++;

       temp = temp->next;
    }

    return l;
}

//Append Last K Nodes
node* kappend(node* &head, int k)
{
    node* newhead;
    node* newtail;
    node* tail = head;
    

   int l = length(head);
   int count = 1;
    k = k%l;
    while(tail->next!=NULL){
       
       if(count == l-k)   newtail = tail;

       if(count == l-k+1)  newhead = tail;

       tail = tail->next;
        count++;

    }


    newtail->next = NULL;
    tail->next = head;

    return newhead;
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

    
    node* newhead = kappend(head,3);
    display(newhead); 

    return 0;
}
