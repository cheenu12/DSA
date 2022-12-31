#include <iostream>              // deletion in singly link-list by given element

using namespace std;

class node{
    public:
int data;
node* next;
node(int dataa)  //constructor called
{
    this->data=dataa;
    this->next=NULL;
}

};
void insertAtHead(node * & head , int value)
{

    node* temp = new node(value);

    temp->next=head;
    head= temp;

}

void print(node * & head )
{

    if(head==NULL){
        cout<<"linklist is empty " <<endl;
    }
 node* temp = head;

    while(temp!= NULL)
    {
        cout<< temp->data<< " " ;
        temp= temp->next;
    }
    cout<<endl;
}

void insertAtTail(node* &tail , int value )
{
    node* temp = new node(value);
    tail->next=temp ;
    tail=temp;

}

void insertAtGiven(node *&head , node* &tail, int position , int data )
{

if(position==1)
{

    insertAtHead(head,data);
    return;
}


    node * temp =head;
    int i=1;
    while(i<position-1)
    {

        temp = temp->next;
        i++;

        if(temp->next==NULL)
{

    insertAtTail(tail,data);
    return;
}
    }
    node * newnode  = new node(data);

    newnode->next =  temp->next;
    temp->next = newnode;

}

void deletenode(node* &head ,node * & tail, int data)  // deleting from given element
{
cout<<"element to be deleted is = " <<data <<endl;
 if(head->data == data)
 {
   node * temp =head;
     head= temp->next;                 // for first element deletion & updating the head
     temp->next=NULL;
     delete temp;
     return;
}
else
{
node * temp = head ;
 node * temp2 = NULL;
 while(temp->data != data)        // pre , current  game
 {                                    // here pre =temp2    ,  current = temp
                                        // until we find the data we updates our temp, temp2
     temp2= temp;
     temp=temp->next;

     if(temp->next==NULL && temp->data != data)   // for printing element not found
     {

         cout<<"element not found"<<endl;
         return;
     }

 }
 if(temp->next == NULL)                   // if element is  at tail & updates the tail
 {
     tail= temp2;
     temp2->next=NULL;
     delete temp;
  return;
 }

 temp2->next= temp->next;                       //changes the pointers because current #temp node is deletd
 temp->next=NULL;
     delete temp;
     return;

    }

}
int main()
{
node* newnode =new node(10);                //creation of first element with the constructor
node * head = newnode;
node * tail= newnode;
print(head);
insertAtHead(head, 12);
print(head);
insertAtTail(tail,22);
print(head);
insertAtGiven(head, tail, 3, 77);
print(head);
insertAtGiven(head, tail, 3, 75);
print(head);
insertAtGiven(head, tail, 5, 1333);
print(head);
insertAtGiven(head, tail, 6, 33);
print(head);
deletenode(head,tail,12);
print(head);
deletenode(head, tail,77);
print(head);
deletenode(head, tail,22);
print(head);
cout<<endl;
cout<<"the data at tail is "<<tail->data<<endl;
cout<<"the data at head is" <<head->data<<endl;
}

