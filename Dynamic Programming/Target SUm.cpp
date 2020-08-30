class Solution {
public:
    int cnt=0;
    int func(vector<int>nums,int S,int i, int sum, vector<vector<int>>memo)
    {
        
        if(i==nums.size()){
            if(sum==S){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(memo[i][sum]!=-1)return memo[i][sum];
        int l= func(nums,S,i+1,sum+nums[i], memo);
        int r= func(nums,S,i+1,sum-nums[i], memo);
        memo[i][sum]= l+r;
        return memo[i][sum];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        vector<vector<int>>memo(100,vector<int>(10000,-1));
        return func(nums,S,0,sum,memo);   
    }
};
