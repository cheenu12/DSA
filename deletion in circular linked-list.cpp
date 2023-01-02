#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node * next ;

    node(int d)
    {
        this->data=d;
        this->next=NULL;
        }
};

void insertnode(node * & tail , int element, int data)
{

    if(tail==NULL)                //if link list is empty
    {

        cout<<"empty" <<endl;

        node* newnode = new node(data);
        tail = newnode;
        newnode->next= newnode;
    }
    else{
        node * temp = tail;
         node * temp2 =  tail;                      // variable for checking is the element is exists or not

             while ( temp->data != element )
             {
                 temp=temp->next;

                 if (temp->data == temp2->data)    // just for finding if the element from where we want to insert (is exits or not)
            {
                cout<<"there is no such element exits  " << element <<" " <<endl;
                cout<<"insert the correct element" <<endl<<endl;
                return;
            }

             }
             //found element
             node * newnode = new node(data);
             newnode->next = temp -> next;
             temp->next= newnode;
cout<<"after inserting : " << data <<endl;
    }
}

void printnode(node * & tail )
{

    if(tail==NULL)
    {

        cout<<"link-list is empty" <<endl;
    }
    else
    {

        node * temp = tail;
        cout<<temp->data << " " ;    //tail ka 1st is printed
        temp=temp->next;
        while ( temp != tail )
        {
            cout<<temp->data << " " ;
            temp=temp->next;
        }
cout<<endl;
        return;
    }
}

void deletion(node * & tail ,  int element)
{
if(tail==NULL)                                          //if link-list is empty
{

    cout<<"link- list is empty" <<endl;
    return;
}


node *prev = tail ;                                     //in deletion prev , current wali game 
node * curr = prev->next;

if(curr ==  prev )                                       // only 1 node is present
{
    tail=NULL;
    cout<<"now link-list is empty" <<endl;
    return;
}

else
{
    while(curr->data != element)           // traversing to find the element  
    {

        prev=curr;                                              // updates them and points them to the next position
        curr=curr->next;


    }

    // found the  element
    prev->next= curr->next;
  if(curr == tail)                        //data to be deleted is at tail so we have to update the tail .
        {
         tail=prev;
        }

    curr->next=NULL;        // deleting current element
    delete curr;
cout<<"after deleting : " << element<<endl;
cout<<endl;

}




}
int main()
{
    node * tail=NULL;
    insertnode (tail, 3 , 11);

 insertnode (tail, 11 ,211);
 insertnode (tail, 211 , 43);
 insertnode (tail, 211 , 1431);
 insertnode (tail, 5 , 9);
 insertnode (tail, 43 , 9);
    printnode(tail);
    deletion(tail, 43);
    printnode(tail);

     insertnode (tail, 211 , 901);
      printnode(tail);
}
