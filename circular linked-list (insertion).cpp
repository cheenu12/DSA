#include <iostream>

using namespace std;

class node
{
public:

    int data;
    node* next;

node(int data)
    {
                this->next= NULL;
                this->data= data;
    }
};

void insertnode (node * & tail ,  int element , int datatoinsert)
{

    if(tail==NULL)                  // if tail is empty we insert the datatoinsert
    {
        cout<< "link-list was empty so i inserted  " << datatoinsert << "  and mark as the tail " <<endl;
        node* newnode = new node(datatoinsert);
        tail= newnode ;
        newnode->next = newnode;

    }


    else
    {
        node * curr = tail ;
        node * curr2 =  tail;                           //temparory variable for just for finding if the element from where we want to insert (is exits or not)
        while ( curr->data != element)
        {

            curr=curr->next ;
            if (curr->data == curr2->data)                  // just for finding if the element from where we want to insert (is exits or not)
            {
                cout<<"there is no such element exits  " << element <<" " <<endl;
                cout<<"insert the correct element" <<endl<<endl;
                return;
            }

        }

        node * newnode = new node(datatoinsert);   //creating new node when element is found 
             newnode-> next = curr->next;
            curr-> next = newnode;

    }
}

void printnode(node * & tail)                    // printing function / traversing
{

 node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
}




int main()
{

    node * tail=NULL;
    insertnode(tail,  3 , 111);
    insertnode(tail,  111 , 112);
    insertnode(tail,  112 , 113);
    insertnode(tail,  1 , 114);
    insertnode(tail,  112 , 115);
     insertnode(tail,  111 , 110);
      insertnode(tail,  113 , 987);
    printnode(tail);


}
