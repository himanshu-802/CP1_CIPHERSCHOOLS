#include<bits/stdc++.h>
using namespace std;
int func(string s)
{
    int a1=0;
    int b1=0;
    int c1=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a')a1=(1+ 2*a1);
        if(s[i]=='b')b1=(a1+ 2*b1);
        if(s[i]=='c')c1=(b1+ 2*c1);
    }
    return c1;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s; cin>>s;
        cout<<func(s)<<endl;
    }
}

