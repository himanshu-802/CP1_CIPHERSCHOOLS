#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>grid;
vector<vector<int>>dp;
int dfs(vector<vector<int>>grid,int i, int j ,int n)
{
	if(i<0 || j<0 || i>=n || j>=n){
		return INT_MIN;
	}
	if(i==n-1){
		return grid[i][j];
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
  return	dp[i][j]= grid[i][j]+ max(dfs(grid,i+1,j,n),max(dfs(grid,i+1,j-1,n), dfs(grid,i+1,j+1,n)))
;}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n; cin>>n;
		dp.assign(n+1,vector<int>(n+1,-1));
		grid.assign(n+1,vector<int>(n+1));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>grid[i][j];
			}
		}
		int ans=INT_MIN;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans=max(ans,dfs(grid,i,j,n));
			}
		}
		cout<<ans<<endl;
	}
}
