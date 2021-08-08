#include<bits/stdc++.h>
using namespace std;

void permute(char s[],int k)
{   static char res[10];
    static int A[10];

    if(s[k]=='\0')
    {   res[k]='\0';
        cout<<res<<'\n';
    }
    else
    {   for(int i=0;s[i]!='\0';i++)
        {   if(A[i]==0)
            {   res[k]=s[i];
                A[i]=1;
                permute(s,k+1);
                A[i]=0;
            }
        }
    }
}

int main()
{   char s[10];
    cout<<"enter the string: \n";
    cin>>s;
    permute(s,0);

return 0;
}