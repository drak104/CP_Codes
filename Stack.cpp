#include<bits/stdc++.h>
using namespace std;

struct Stack
{   int top;
    int *s;
    int size;
};

void Create(Stack *st)
{
    cout<<"enter size: ";
    cin>>st->size;
    st->top=-1;
    st->s=new int[st->size];
}

void Display(Stack st)
{   for(int i=st.top;i>=0;i--)
    cout<<st.s[i]<<" ";
    cout<<endl;
}

void push(Stack *st,int val)
{   if(st->top == st->size-1)
    cout<<"stack overflow\n";
    else
    {   st->top++;
        st->s[st->top]=val;
    }
}

int pop(Stack *st)
{   int x=-1;
    if(st->top==-1)
    cout<<"Stack Underflow";
    else
    x=st->s[st->top--];
    return x;
}

int main()
{   Stack st;
    Create(&st);
    push(&st,1);
    push(&st,9);
    push(&st,4);
    push(&st,10);
    Display(st);
    cout<<pop(&st);
    cout<<endl;
    Display(st);
return 0;
}