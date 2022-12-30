#include <iostream>

using namespace std;
class node
{

public:

    int data ;
    node* next;
    node* prev;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev= NULL;
    }
};
int getlength(node* &head)
{
  node* temp = head;
    int count=0;
    while(temp!= NULL)
    {
     temp= temp->next;
        count++;
    }
    return count;

}
void print(node* &head)
{
    node* temp = head;

    while(temp!= NULL)
    {
        cout<<temp->data<<"  ";
     temp= temp->next;

    }
    cout<<endl;
}
void insertAtHead(node* & head , int data)
{
     node* newnode = new node(data);


     newnode->next= head;
     head->prev= newnode->next;
     head= newnode;

}
void insertAtTail(node* &tail, int data)
{
    node* temp = new node(data);
    tail->next=temp;
    temp->prev=tail;
    tail= temp;

}
void insertAtPosition(node*&head , node*&tail , int position , int data)
{

 if(position==1)
 {
     insertAtHead(head, data);
 }
 else
 {
    node * temp = head ;
    int i=1;
    while (i < position - 1 )
    {

        temp= temp ->next ;
        i++;
    }

    if(temp ->next ==NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    node * newnode= new node(data);
     newnode-> next = temp->next;
     temp->next = newnode;
     newnode->prev = temp;
     temp->next->prev = newnode;
 }




}
int main()
{

    node* newnode= new node(23);
    node*head= newnode;
    node* tail= newnode;
    print(head);
    insertAtHead(head, 12);
    insertAtTail(tail, 13);
     insertAtHead(head, 14);
      insertAtHead(head, 42);
    print(head);
    insertAtTail(tail, 11);
    insertAtTail(tail, 15);
     print(head);
     insertAtPosition(head, tail, 5, 99);
      print(head);
       insertAtPosition(head, tail, 1, 43);
      print(head);
       insertAtPosition(head, tail, 10, 32);
      print(head);
    cout<<"the length of the node is = " << getlength(head);
    cout<<"head ka data"<<head->data;
    cout<<"tail ka data"<<tail->data;
    }
