class Solution {
public:
    int func(string word1, string word2, int m, int n, vector<vector<int>>&dp)
    {
        if(m==0)return n;
        if(n==0)return m;
        if(word1[m-1]==word2[n-1]){
            return func(word1,word2,m-1,n-1,dp);
        }
        if(dp[m][n]!=-1)return dp[m][n];
        dp[m][n]= 1+ min(func(word1,word2,m-1,n,dp), min( func(word1,word2,m,n-1,dp), func(word1,word2,m-1,n-1,dp)));
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
         int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+5,vector<int>(n+5,-1));
       
        return func(word1,word2,m,n,dp);
    }
};
