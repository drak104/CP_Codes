#include<bits/stdc++.h>
using namespace std;

void PQ(queue<char> q1,queue<char> q2,queue<char> q3)
{   char y;
    while(!q3.empty()) 
    {    if(!q1.empty())
        {   y=q1.front();
            q1.pop();
            cout<<y<<endl;
        }    
        else if(!q2.empty())
        {   y=q2.front();
            q2.pop();
            cout<<y<<endl;
        }    
        else if(!q3.empty())
        {   y=q3.front();
            q3.pop();
            cout<<y<<endl;
        }    
        else
        {   cout<<"empty\n";
        }
    }
}

int main()
{   queue<char> q1,q2,q3;
    int n,p;
    char x,y;
    cout<<"size: \n";
    cin>>n;
    for(int i=0;i<n;i++)
    {   cout<<"enter element: \n";    
        cin>>x;
        cout<<"enter Priority: \n";    
        cin>>p;
        if(p==1)
        q1.push(x);
        else if(p==2)
        q2.push(x);
        else
        q3.push(x);    
    }
    PQ(q1,q2,q3);
return 0;
}