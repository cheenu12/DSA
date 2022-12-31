#include <iostream>

using namespace std;


class node
{

public:

    int data;
    node* next;
    node * prev;
    node (int data)
    {

        this-> data =  data;
        this -> next = NULL;
        this-> prev= NULL;

    }


};
void insertATHead(node* & head , node * &tail, int data)
{
    if(head==NULL)
    {
        cout<<"empty ll and i have added an element "  << data <<"at head "<<endl;
        node * newnode= new node(data);
        head = newnode;
        tail = newnode ;
 }
 else
 {
     node* newnode = new node(data);
     newnode->next =  head;
     head->prev = newnode;
     head= newnode;

 }

}

void insertAtTail(node* & head , node * &tail, int data)
{
    if(head== NULL)
    {
         cout<<"empty ll and i have added an element "<< data <<"at tail" <<endl;
        node * newnode= new node(data);
        head = newnode;
        tail = newnode ;
    }

    else
    {
        node* newnode = new node(data);

        tail->next = newnode;
        newnode->prev = tail ;
        tail =  newnode;

    }


}

void insertAtPosition(node* & head , node * &tail, int data, int  position)
{

    if(position==1)
    {

        insertATHead(head, tail, data);
    }

    else
    {
        node * temp = head;
        int i=1;
        while (i< position-1)
        {
            temp = temp->next;
            i++;

        }

        if(temp->next == NULL)
        {

            insertAtTail(head, tail, data);
            return;
        }

        else
        {
         node * newnode = new node (data);

         newnode-> next = temp ->next;
         temp->next->prev= newnode;
         temp->next = newnode;
         newnode->prev= temp;
        }

    }

}

void print(node* &head )
{
    node* temp = head ;
    while (temp != NULL)
    {
        cout<<temp->data <<" " ;
        temp = temp-> next ;
    }
    cout<<endl;
}
int main()
{
node * head=NULL;
node * tail= NULL;
insertATHead (head, tail, 33);
insertATHead (head, tail, 34);
print(head);
insertAtTail(head, tail, 1);
insertAtTail(head, tail, 66);
insertAtTail(head, tail,45);
print(head);
insertAtPosition(head , tail, 44, 4);
insertAtPosition(head , tail, 12, 1);
insertAtPosition(head , tail, 6543, 8);
print(head);
cout<< "data at tail " << tail->data <<endl;
cout<<"data at head " << head -> data;
}
