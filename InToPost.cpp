#include<bits/stdc++.h>
using namespace std;

int pre(char c)
{   if(c == '+' || c == '-')
    return 1;
    else if(c == '*' || c == '/')
    return 2;
    else
    return 3;
}

int main()
{   string in="a+*+e";
    int l=in.length();
    char post[l+1];
    stack<char> s;
    int i=0,j=0;
    while(in[i]!='\0')
    {   if(s.empty())
        s.push(in[i++]);
        else if(pre(in[i])<=pre(s.top()))
        {   post[j++]=s.top();
            s.pop();
        }
        else
          s.push(in[i++]);
    }
    while(!s.empty())
    {   post[j++]=s.top();
        s.pop();
    }
    post[j]='\0';
    for(int k=0;post[k]!='\0';k++)
        cout<<post[k];
return 0;
}