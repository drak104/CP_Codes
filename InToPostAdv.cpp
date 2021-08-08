#include<bits/stdc++.h>
using namespace std;

int pre(char c,int f)
{   
    if(c == '+' || c == '-')
    return 1+f;
    else if(c == '*' || c == '/')
    return 3+f;
    else if(c == '^')
    return 5+f;         //assuming precednce L->R, for R->L, change it to 6-f
    else if(c== '(')
    return (1-f)*7;
    else if(c==')')
    return 0;
    else
    return 8;
}

int main()
{   string in="A+B*C/(E-F)^M^K-D";
    int l=in.length(),p=0;
    int flag[l]={0};
    char post[l+1];
    stack<char> s;
    int i=0,j=0;
    while(in[i]!='\0')
    {   if(s.empty())
        {   s.push(in[i]);
            flag[i]++;
            p=i++;
        }
        else if(in[i]==')' && s.top()=='(')
        {   s.pop();
            p--;
            i++;
        }
        else if(pre(in[i],flag[i])<=pre(s.top(),flag[p]))
        {   
            post[j++]=s.top();
            s.pop();
            p--;
        }
        else
        {   s.push(in[i]);
            flag[i]++;
            p=i++;
        }
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