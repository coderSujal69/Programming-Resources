#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev, *next;
};

class Dlinkedlist
{
    node *start, *end;

public:
    Dlinkedlist()
    {
        start = end = NULL;
    }
    void addAtBeg(int);
    void append(int);
    void addAfter(int, int);
    void del(int);
    int count();
    void display();
};

void Dlinkedlist ::addAtBeg(int n)
{

    node *temp = new node;
    temp->data = n;
    temp->prev = NULL;
    temp->next = start;
    if (start != NULL)
    {
        start->prev = temp;
        start = temp;
    }
}

void Dlinkedlist ::append(int n)
{

    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = end = temp;
    }
    else
    {
        temp->prev = end;
        end->next = temp;
        end = temp;
    }
}
int Dlinkedlist ::count()
{
    if (start == NULL)
    {
        return 0;
    }
    else
    {
        int c = 1;
        node *t;
        t = start;
        while (t->next != NULL)
        {
            t = t->next;
            ++c;
        }
        return c;
    }
}
void Dlinkedlist::addAfter(int loc, int n)
{

     
    int c = count();

    if ( loc < 0 || loc>c)
    {
        cout << "\nNot a valid location ";
    }

    else if (loc == 0)
    {
        addAtBeg(n);
    }
    else if (loc==c)
    {
        append(n);
    }
    
    else
    {
        node *temp,*t;
        temp=new node;
        temp->data=n;
        t=start;

        for (int i = 1; i < loc ; i++)
        {
            t=t->next;
            t->next->prev = temp;
            temp->next = t->next;
            temp->prev = t;
            t->next=temp;
        }
    }
}

int main()
{
         int c,n,loc;
        Dlinkedlist L;
        cout<<"\nEnter a number to add at the beginning  ";
        cin>>n;
        L.addAtBeg(n);

        cout<<"\nEnter location and number to insert an element  ";
        cin>>loc>>n;
        L.addAfter(loc,n);
        c=L.count();
        cout<<"\nNumber of elements in the linked list :"<<c<<endl;
        // cout<<"\nElements of linked list are :"<<endl;
        // L.display();
        //  cout<<"\nEnter a number to append in the linked list ";
        // cin>>n;
        // L.append(n);
        //  cout<<"\nEnter a number to Delete";
        // cin>>n;
        // L.del(n);
        //   cout<<"Elements of linked list after deletion  are :"<<endl;
        // L.display();
        //  c=L.count();
        // cout<<"\nNumber of elements in the linked list After deletion are :"<<c;
    return 0;
}