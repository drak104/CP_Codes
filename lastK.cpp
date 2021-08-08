#include<bits/stdc++.h>
using namespace std;

int nod(int n)
{   int c=0;
    while(n>0)
    {   n/=10;
        c++;
    }
return c;
}

int lastthree(int n,int k)
{   int A[k],ans=0;
    for(int i=0;i<k;i++)
    {   A[i]=n%10;
        n/=10;
    }
    for(int i=k-1;i>=0;i--)
    {   ans*=10;
        ans+=A[i];
    }
return ans;
}

int main()
{   int a,b,k,res=1;
    cin>>a>>b>>k;
    for(int i=0;i<b;i++)
    {   res*=a;
        if(nod(res)>k)
        {   res=lastthree(res,k);
        }
    }
    if(res==0)
    {   for(int i=0;i<k;i++)
        cout<<0;
    }
    else
    cout<<res<<endl;
return 0;
}