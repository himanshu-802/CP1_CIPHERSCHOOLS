#include<bits/stdc++.h>
using namespace std;
bool func(int arr[],int n, int s)
{
	if(n==0 && s!=0)return false;
	if(s==0)return true;
	if(s<0)return false;
	return func(arr,n-1,s) || func(arr,n-1,s-arr[n-1]);
}
int p,q,r;
int dp[100000];
int func2(int n)
{
	dp[0]=0;
	for(int i=0;i<=n;i++){
		if(dp[i]==-1)continue;
		if(i+p<=n)dp[i+p]=max(dp[i+p],dp[i]+1);
		if(i+q<=n)dp[i+q]=max(dp[i+q],dp[i]+1);
		if(i+r<=n)dp[i+r]=max(dp[i+r],dp[i]+1);
	}
	return dp[n];
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
			memset(dp,-1,sizeof(dp));
		int n;cin>>n;
		cin>>p>>q>>r;
		cout<<func2(n)<<endl;
	
	}
}
