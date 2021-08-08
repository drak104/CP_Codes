#include<bits/stdc++.h>
using namespace std;

int main()
{   stack<int> s;
    int x,y,i,r;
    string st;
    cout<<"enter: ";
    cin>>st;
    while(i<st.length())
    {   if(st[i]-'0'>=0 && st[i]-'0'<9)
        s.push(st[i]-'0');
        else
        {   y=s.top();
            s.pop();
            x=s.top();
            s.pop();
                switch(st[i])
                {   case '+': r=x+y; break;
                    case '-': r=x-y; break;
                    case '*': r=x*y; break;
                    case '/': r=x/y; break;
                }
            s.push(r);                    
        }
        i++;
    }
cout<<s.top();
return 0;
}