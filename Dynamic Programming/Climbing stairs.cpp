class Solution {
public:
    int func(int n,vector<int>&dp)
    {
        if(n==0){
            return 1;
        }
        if(n<0)
        {
            return 0;
        } 
        if(dp[n]!=-1)return dp[n];
        dp[n]= func(n-1,dp)+func(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(1000000,-1);
        return func(n,dp);
    }
};
