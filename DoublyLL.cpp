#include<bits/stdc++.h>
using namespace std;

struct Node     //defining a DLL node
{   int data;
    Node *prev;
    Node *next;
}   *first=NULL;

void Create(int A[],int n)      //creating a DLL
{   first=new Node;
    Node *last,*t;
    first->data=A[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {   t=new Node;
        t->data=A[i];
        last->next=t;
        t->prev=last;
        t->next=NULL;
        last=t;
    }
}

void Display(Node *p)       //Displaying a DLL
{   while(p)
    {   cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void Insert(Node *p,int pos,int val)    //Inserting in a DLL
{   Node *t,*q;
    t=new Node;
    t->data=val;
    q=p;
    if(pos==1)
    {   t->next=p;
        p->prev=t;
        first=t;
    }
    else
    {   for(int i=1;i<pos;i++)
        {   q=p;
            p=p->next;
        }
        if(p)
        {   t->prev=q;
            q->next=t;
            t->next=p;
            q=t;
        }
        else
        {   q->next=t;
            t->prev=q;
            t->next=NULL;
        }
    }
}

void Delete(Node *p,int pos)    //deleting from a DLL
{   Node *q;
    if(pos==1)
    {   first=p->next;
        first->prev=NULL;
        free(p);
    }
    else
    {   for(int i=1;i<pos;i++)
        {   q=p;
            p=p->next;
        }
        if(p->next)
        {   q->next=p->next;
            p->next->prev=q;
            free(p);
        }
        else
        {   p->prev->next=NULL;
            free(p);
        }
    }
}

void Reverse(Node *p,Node *q)       //reversing a DLL using Recursion
{    if(!p)
    {   first=q;
        first->prev=NULL;
        return;
    }
    Reverse(p->next,p);
    p->next=q;
    if(q)
    q->prev=p;

}


void Rev(Node *p)        //reversing a DLL using sliding pointers
{   Node *q=NULL,*r=NULL;
    while(p)
    {   r=q;
        q=p;
        p=p->next;
        q->next=r;
        if(r)
        r->prev=q;
    }
    q->prev=NULL;
    first=q;
}


/* Above mentioned functions with their prototypes are written, use the main function to access them for the Doubly linked lists */

int main()
{   int A[]={1,5,9,31,58,69,12};
    Create(A,7);
    Display(first);
    Rev(first);
    Display(first);
return 0;
}