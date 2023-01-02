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

    if(tail==NULL)
    {
        cout<< "link-list was empty so i inserted  " << datatoinsert << "  and mark as the tail " <<endl;
        node* newnode = new node(datatoinsert);
        tail= newnode ;
        newnode->next = newnode;

    }


    else
    {
        node * curr = tail ;
        node * curr2 =  tail;
        while ( curr->data != element)
        {

            curr=curr->next ;
            if (curr->data == curr2->data)
            {
                cout<<"there is no such element exits  " << element <<" " <<endl;
                cout<<"insert the correct element" <<endl<<endl;
                return;
            }

        }

        node * newnode = new node(datatoinsert);
             newnode-> next = curr->next;
            curr-> next = newnode;

    }
}

void printnode(node * & tail)
{

if(tail==NULL)
{

    cout<<"link-list is empty "<<endl;
    return;
}


node * ttt = tail;
cout<<tail->data << " ";
tail= tail->next ;
while(  tail != ttt )

{
    cout<< tail->data << " " ;
   tail=  tail->next;
}
cout<<endl;
return;
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
