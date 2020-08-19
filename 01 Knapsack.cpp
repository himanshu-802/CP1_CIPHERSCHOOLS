#include<bits/stdc++.h>
using namespace std;
int func(int wt[],int val[],int n, int W)
{
    if(n==0 || W==0)return 0;
    if(wt[n-1]>W)return func(wt,val,n-1,W);
    return max(func(wt,val,n-1,W), val[n-1]+func(wt,val,n-1,W-wt[n-1]));
}
int main()
{
    int t ;cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int W; cin>>W;
        int wt[n];int val[n];
        for(int i=0;i<n;i++)cin>>val[i];
        
        for(int i=0;i<n;i++)cin>>wt[i];
        cout<<func(wt,val,n,W)<<endl;
    }
}
