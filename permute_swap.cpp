#include<bits/stdc++.h>
using namespace std;

void swap(char &A,char &B)
{   char temp;
    temp = A;
    A = B;
    B = temp;
}

void permute(char s[],int l,int h)
{   if(l==h)
    cout<<s<<endl;
    else
    {   for(int i=l;i<=h;i++)
        {   swap(s[i],s[l]);
            permute(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}

int main()
{   char s[10];
    int n;
    cout<<"enter size: \n";
    cin>>n;
    cout<<"enter: \n";
    cin>>s;
    cout<<n<<endl;
    permute(s,0,n-1);
return 0;
}