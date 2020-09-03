#include<bits/stdc++.h>
using namespace std;
int dp[100000];
int func(int n)
{
	if(n==0){
		return 1;
	}
	if(n<0)return 0;
	if(dp[n]!=-1)return dp[n];
	return dp[n]=func(n-1)+func(n-2)+func(n-3);
	
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		memset(dp,-1,sizeof(dp));
		cout<<func(n)<<endl;
	}
}
