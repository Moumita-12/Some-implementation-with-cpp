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

//intersecting
void intersect(node* &head1, node* &head2, int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next=temp1;
}

//intersection of 2 nodes
int intersection(node* &head1, node* &head2)
{
    node* ptr1;
    node* ptr2;
    
   int l1 = length(head1);
   int l2 = length(head2);

   int d = 0;
   if(l1>l2) {  
    d = l1 - l2;
   ptr1 = head1;
   ptr2 = head2;
   }
   else{
   d = l2 - l1;
   ptr1 = head2;
   ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1 == NULL)   return -1;

        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1 == ptr2) return ptr1->data;

        ptr1= ptr1->next;
        ptr2= ptr2->next;

    }


    return -1;
}


int main(){
    
    node* head1 =NULL;
    node* head2 =NULL;
    insert_at_tail(head1,1);
    insert_at_tail(head1,2);
    insert_at_tail(head1,3);
    insert_at_tail(head1,4);
    insert_at_tail(head1,5);
    insert_at_tail(head1,6);

    insert_at_tail(head2,9);
    insert_at_tail(head2,10);

    intersect(head1,head2,6);

    display(head1);
    display(head2);

    cout<<intersection(head1, head2)<<endl;

    return 0;

}
