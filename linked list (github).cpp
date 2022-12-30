#include <iostream>

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
int main()
{

node* newnode =new node(10);  //creation of first element with the constructor
node * head = newnode;
node * tail= newnode;
print(head);
insertAtHead(head, 12);
print(head);
insertAtHead(head, 112);
print(head);
insertAtTail(tail,22);
print(head);
insertAtGiven(head, tail, 3, 77);
print(head);
insertAtGiven(head, tail, 1, 337);
print(head);
insertAtGiven(head, tail, 7, 123);
print(head);
cout<<endl;
cout<<"the data at tail is "<<tail->data;
cout<<"the data at head is" <<head->data;
}
