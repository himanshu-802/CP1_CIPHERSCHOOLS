class Solution {
public:
    int func(int n,vector<int>&dp)
    {
        if(sqrt(n)==floor(sqrt(n)))return 1;
        if(n<=3){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int res=n;
        for(int i=1;i<=sqrt(n);i++)
        {
            int temp=i*i;
            res= min(res,1+func(n-temp,dp));
        }
    dp[n]= res;
        return res;
    }
    int numSquares(int n) {
        vector<int>temp(100000,-1);
     return func(n,temp);   
    }
};
