class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     int n=coins.size();
        vector<int>wt=coins;
        int W=amount;
        int dp[n+1][W+1];
		for(int i=0;i<=W;i++)
		{
			dp[0][i]=INT_MAX;
		}
		for(int i=1;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int j=1;j<=W;j++)
        {
            if(j%wt[0]==0){
                dp[1][j]=j/wt[0];
            }
            else{
                dp[1][j]=INT_MAX-1;
            }
        }
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=W;j++)
			{
				
				 if( wt[i-1]>j)dp[i][j]=dp[i-1][j];
				else dp[i][j]= min(dp[i-1][j] ,1 + dp[i][j-wt[i-1]]);
			}
		}
        // cout<<n<<" "<<W<<endl;
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=W;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        if( dp[n][W]==INT_MAX || dp[n][W]==INT_MAX-1)return -1;
        return dp[n][W];
    }
};
