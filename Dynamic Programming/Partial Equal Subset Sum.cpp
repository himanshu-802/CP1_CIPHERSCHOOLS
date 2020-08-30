class Solution {
public:
    bool func(vector<int>nums, int sum, int n, unordered_map<int,int>&dp)
    {
        if(sum==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp.find(sum)!=dp.end()){
            return dp[sum];
        }
        int result= func(nums,sum-nums[n-1],n-1,dp) || func(nums,sum,n-1,dp);
        dp[sum]=result;
        return dp[sum];
    }
    bool canPartition(vector<int>& nums) {
     unordered_map<int,int>dp;
     int sum=0;
     int n=nums.size();
     for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2==1)return false;
        else{
            return func(nums,sum/2,n,dp);
        }
    }
};
