// Similar to unbounded knapsack 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int wt[n];
		for(int i=0;i<n;i++)cin>>wt[i];
		int W; cin>>W;
		int dp[n+1][W+1];
		for(int i=0;i<=n;i++)
		{
			dp[i][0]=1;
		}
		for(int i=0;i<=W;i++)
		{
			dp[0][i]=0;
		}
		
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=W;j++)
			{
				
				 if( wt[i-1]>j)dp[i][j]=dp[i-1][j];
				else dp[i][j]= dp[i-1][j] + dp[i][j-wt[i-1]];
			}
		}
		cout<<dp[n][W]<<endl;
	}
}
