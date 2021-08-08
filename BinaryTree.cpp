#include<bits/stdc++.h>
using namespace std;

struct Node
{   Node *lc;
    int data;
    Node *rc; 
};

class Tree
{   public:
    Node *root;
    Tree()
    {root=NULL;}
    void create();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void IPreorder(Node *p);
    void IPostorder(Node *p);
    void IInorder(Node *p);
    void LevelOrder(Node *p);
};

void Tree::create()
{   Node *p,*t;
    int x;
    queue<Node*> q;
    root=new Node;
    cout<<"enter root: \n";
    cin>>x;
    root->data=x;
    root->lc=root->rc=NULL;
    q.emplace(root);

    while(!q.empty())
    {   p=q.front();
        q.pop(); 
        cout<<"enter the left child of "<<p->data<<" :\n";
        cin>>x;
        if(x!=-1)
        {   t=new Node;
            t->data=x;
            t->lc=t->rc=NULL;
            p->lc=t;
            q.emplace(t);
        }
        cout<<"enter the right child of "<<p->data<<" :\n";
        cin>>x;
        if(x!=-1)
        {   t=new Node;
            t->data=x;
            t->lc=t->rc=NULL;
            p->rc=t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(Node *p)
{   if(p)
    {   cout<<p->data<<" ";
        Preorder(p->lc);
        Preorder(p->rc);
    }
}

void Tree::Postorder(Node *p)
{   if(p)
    {   
        Postorder(p->lc);
        Postorder(p->rc);
        cout<<p->data<<" ";
    }
}

void Tree::Inorder(Node *p)
{   if(p)
    {   
        Inorder(p->lc);
        cout<<p->data<<" ";
        Inorder(p->rc);
    }
}

void Tree::IPreorder(Node*p)
{   Node* t=p;
    stack<Node*> s;
    while(t || !s.empty())
    {   if(t)
        {   cout<<t->data<<" ";
            s.push(t);
            t=t->lc;
        }
        else
        {   t=s.top();
            s.pop();
            t=t->rc;
        }
    }
}

void Tree::IInorder(Node*p)
{   Node* t=p;
    stack<Node*> s;
    while(t || !s.empty())
    {   if(t)
        {   
            s.push(t);
            t=t->lc;
        }
        else
        {   
            t=s.top();
            s.pop();
            cout<<t->data<<" ";
            t=t->rc;
        }
    }
}

void Tree::IPostorder(Node*p)
{   Node* t=p;
    stack<Node*> s;
    long temp;
    while(t || !s.empty())
    {   if(t)
        {   
            s.push(t);
            t=t->lc;
        }
        else
        {   
            temp=s.top();
            s.pop();
            if(temp>0)
            {   s.push(-temp);
                t=((Node*)temp)->rc;
            }
            else   
            {   cout<<t->data<<" ";
                t=NULL;
            }
        }
    }
}

void Tree::LevelOrder(Node*p)
{   queue<Node *> ql;
    Node *t;
    ql.push(p);
    cout<<p->data<<" ";
    while(!ql.empty())
    {   t=ql.front();
        if(t->lc)
        {   cout<<t->lc->data<<" ";
            ql.push(t->lc);
        }
        if(t->rc)
        {   cout<<t->rc->data<<" ";
            ql.push(t->rc);
        }
        ql.pop();
    }
    
}

int main()
{   Tree tree;
    tree.create();
    // tree.IPreorder(tree.root);
    // cout<<endl;
    // tree.IPostorder(tree.root);
    // cout<<endl;
    // tree.IInorder(tree.root);
    // cout<<endl;
    tree.LevelOrder(tree.root);
return 0;
}