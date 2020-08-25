class Solution {
public:
    
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>>dp(n,vector<int>());
        for(int i=0;i<n;i++)
        {
            if(i==0)dp[i].push_back(1);
            else if(i==1){
                dp[i].push_back(1);
                dp[i].push_back(1);
            }
            else{
                dp[i].push_back(1);
                for(int j=0;j<i-1;j++)
                {
                    dp[i].push_back(dp[i-1][j]+dp[i-1][j+1]);
                }
                dp[i].push_back(1);
            }
        }
        return dp;
        
        
    }
};
