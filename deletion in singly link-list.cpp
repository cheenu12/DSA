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

void deletenode(node* &head ,node * & tail, int position)
{

if(head==NULL)
{

    cout<<"link list is already empty" <<endl;
    return;
}

    if(position==1)
    {
        node* temp= head;
        head=head->next;            // deleting at position first
        temp->next=NULL;
        delete temp;                // we have to delete manually because its a its a heap memory..
    }
    else
    {
        // node* temp = head;
        int count=1;
        node * current= head;
        node * previ = NULL;

        while(count < position  )                       // previous and current node concept is there
        {                                                 // view notebook for refrence
            previ = current;
            current= current->next;
            count++;


        }
        if(current->next==NULL)                 // to update the tail, when we are deleting the last node
        {

            tail=previ;
        }

        previ->next= current->next;
        current->next =NULL;                    // to break the second  connection refer the notebook
        delete current;                      // we have to delete manually because its a its a heap memory..

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
insertAtGiven(head, tail, 5, 123);
print(head);
deletenode(head,tail,4);
print(head);
deletenode(head,tail, 1);
print(head);
insertAtHead(head, 32);
print(head);
insertAtTail(tail,87);
print(head);
deletenode(head,tail,2);
print(head);
cout<<endl;
cout<<"the data at tail is "<<tail->data<<endl;
cout<<"the data at head is" <<head->data<<endl;
}


