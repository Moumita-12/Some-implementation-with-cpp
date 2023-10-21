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

void makecycle(node* &head, int pos){

    node* temp = head;
    node* startnode;

    int count = 1;
    while(temp->next != NULL){
      
      if(count == pos)  startnode = temp;

        temp = temp->next;
        count++;
    }

    temp->next = startnode;

}

 bool detectcycle(node* &head){

    node* slow = head;
    node* fast = head;

    while(fast!= NULL && fast->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
        return true;
    }

    }

    
    return false;
 }

 void removecycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) break;
    }

    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
   slow->next=NULL;

    

   /*

     // for return the 1st node of cycle  (can be replaced with last part above)

      node* slow2 = head;
    while(slow2!= fast){
        slow2 = slow2->next;
        fast = fast->next;
    }
    cout<<slow2->data<<endl;

   
   */
 }

     



int main(){
    
    node* head =NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);


    
    
   makecycle(head,3);
    //display(head);

   cout<<detectcycle(head)<<endl;

   removecycle(head);

   cout<<detectcycle(head)<<endl;

   display(head);

    return 0;
}
