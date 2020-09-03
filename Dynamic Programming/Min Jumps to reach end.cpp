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

int minJumps(int arr[],int n)
{
	if(n==1){
		return 0;
	}
	int res=INT_MAX;
	
	for(int i=n-2;i>=0;i--)
	{
		if(i+arr[i]>=n-1){
			int sub_res=minJumps(arr,i+1);
			if(sub_res!=INT_MAX){
				res=min(res,sub_res+1);
				//dp[n]=res;
			}
		}
	}
	return res;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)cin>>arr[i];
		memset(dp,-1,sizeof(n+1));
		cout<<minJumps(arr,n)<<endl;
	    
	}
}
