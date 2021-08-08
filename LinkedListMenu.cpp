#include<bits/stdc++.h>
using namespace std;

struct Node     //defining Nodes
{   int data;
    Node *next;
} *first, *second, *head, *third;

void Create(int A[],int n)  //creating a simple linked list
{   Node *t,*last;
    first=(Node*)malloc(sizeof(Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {   t=(Node*)malloc(sizeof(Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int Count(Node *p)  //counting number of nodes in a LL
{   int C=0;
    while(p)
    {   p=p->next;
        C++;
    }
return C;
}

int Search(Node *p,int val)     //Searching for a value
{   int pos=0;
    while(p)
    {   pos++;
        if(p->data==val)
        return pos;
        p=p->next;
    }
    return -1;
}

void Insert(Node *p,int pos,int val)    //inserting at a desired position
{   Node *t,*q=NULL;
    t=(Node*)malloc(sizeof(Node));
    t->data=val;
    if(pos==1)  
    {   t->next=first;
        first=t;
    }
    else
    {   for(int i=1;i<pos;i++)
        {   q=p;
            p=p->next;
        }
        q->next=t;
        t->next=p;
    }
}

void SortedInsert(Node *p,int val)  //inserting in a sorted array, at the dedicated position
{   Node *t,*q;
    t=new Node;
    t->data=val;
    if(p->data > val)
    {   t->next=p;
        first=t;
        return;
    }
    while(p)
    {   q=p;
        p=p->next;
        if(p && p->data>val)
        {   q->next=t;
            t->next=p;
            return;
        }
    }
    q->next=t;
    t->next=NULL;
}

void Delete(Node *p,int pos)    //deleting from any position
{   Node *q=NULL;
    if(pos==1)
    {   first=p->next;
        free(p);
    }
    else
    {   for(int i=1;i<pos;i++)
        {   q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
    }
}

void Display(Node *p)       //Displaying the LL
{   while(p)
    {   cout<<p->data<<" ";
        p=p->next;
    }
cout<<endl;
}

int CheckSort(Node *p)  //checking if the LL is sorted
{   Node *q;    
    for(int i=0;i<Count(first)-1;i++)
    {   q=p->next;
        if(p->data>q->data)
        return 0;
        p=p->next;
    }
    return 1;
}

int Checkloop(Node *p)  //checking if LL has a loop
{   Node *q=p;
    do
    {   p=p->next;
        q=q->next;
        if(p)
        p=p->next;
    }while(p && p!=q);
if(p)
return 1;
else
return 0;
}

void RemDupli(Node *p)  //to remove duplicates from a sorted LL
{   Node *q=p,*r=q;
    p=p->next;
    while(r)
    {   if(p->data==q->data)
        {   r=p->next;
            q->next=r;
            free(p);
            p=r;
        }
        else
        {   q=p;
            if(p->next)
            p=p->next;
            else
            break;
        }
    }
}

void Reverse(Node *p,Node *q)   //to reverse a LL using recursion
{   
    if(p==NULL)
    {   first=q;
        return;
    }
    Reverse(p->next,p);
    p->next=q;
}

void Rev(Node *p)       //to reverse a LL using sliding pointers
{   Node *q=NULL,*r=NULL;
    q=p;
    p=p->next;
    while(q)
    {   q->next=r;
        r=q;
        q=p;
        if(p)
        p=p->next;
    }
    first=r;
}

void CreateB(int B[],int n)     //to create another LL for two LL operations
{   Node *t,*last;
    second= new Node;
    second->data=B[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++)
    {   t=new Node;
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Concat(Node *p,Node *q)       //to concat two LL's
{   third=p;
    while(p->next!=NULL)
    p=p->next;
    p->next=q;
}

void Merge(Node *p,Node *q)     //to merge 2 sorted LL's to a single merged sorted LL
{   Node *last;
    if(p->data <= q->data)
    {   last=p;
        third=p;
        p=p->next;
    }
    else
    {   last=q;
        third=q;
        q=q->next;
    }
    while(p && q)
    {   if(p->data <= q->data)
        {   last->next=p;
            last=p;
            if(p)
            p=p->next;
        }
        else
        {   last->next=q;
            last=q;
            if(q)
            q=q->next;
        }
    }
    if(p)
    last->next=p;
    else if(q)
    last->next=q;
}

void CreateC(int C[],int n)     //to create a circular LL
{   Node *t,*last;
    head= new Node;
    head->data=C[0];
    last=head;
    for(int i=1;i<n;i++)
    {   t=new Node;
        t->data=C[i];
        last->next=t;
        last=t;
    }
    last->next=head;
}

int CountC(Node *p)     //to count Number of Nodes in a LL
{   int C=0;
    do
    {   p=p->next;
        C++;
    } while(p!=head);
return C;
}

void DisplayC(Node *p)  //displaying a circular LL
{   do
{   cout<<p->data<<" ";
    p=p->next;
} while (p!=head);
cout<<endl;
}

void InsertC(Node *p,int pos,int val)   //inserting in a CLL
{   Node *t,*q;
    t=new Node;
    t->data=val;
    if(pos==1)
    {   while(p->next!=head)
        p=p->next; 
        t->next=head;
        head=t;
        p->next=t;
    }
    else
    {   for(int i=1;i<pos;i++)
        {   q=p;
            p=p->next;
        }
        q->next=t;
        t->next=p;
    }
}

void DeleteC(Node *p,int pos)       //deleting from a CLL
{   if(pos< 1 || pos>CountC(head))
    return;
    Node *q;
    if(pos==1)
    {   while(p->next!=head)
        p=p->next;
        q=head->next;
        p->next=q;
        free(head);
        head=q;
    }
    else
    {   for(int i=1;i<pos;i++)
        {   q=p;
            p=p->next;
        }
    q->next=p->next;
    free(p);
    }
}

/* all the functions of this menu are mentioned above with their prototypes, have fun */

int main()
{   int A[]={100,100,50,40,40,20,10};
    int B[]={1,3,4,6,9,11};
    int C[]={3,5,7,8,10};
    Create(A,7);
    // CreateB(B,6);
    // CreateC(C,5);
    Display(first);
    RemDupli(first);
    Display(first);
    // Display(second);
    // DisplayC(head);
return 0;
}