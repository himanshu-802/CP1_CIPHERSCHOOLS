#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int price[n];
		 int wt[n];
		for(int i=0;i<n;i++)
		{
			cin>>price[i];
			wt[i]=i+1;
		}
		 int dp[n+1][n+1];
		 for(int i=0;i<=n;i++)
		 {
		 	for(int j=0;j<=n;j++)
		 	{
		 	  if(i==0 || j==0)dp[i][j]=0;
		 	  else if(wt[i-1]>j)dp[i][j]=dp[i-1][j];
			else dp[i][j]=max( dp[i-1][j], price[i]+dp[i-1][j-wt[i-1]]);	
			}
		 }
		cout<<dp[n][n]<<endl;
	}
}
