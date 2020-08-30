class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
     int minval=nums[0];
     int maxval=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0){
                swap(minval,maxval);
            }
            maxval=max(nums[i],nums[i]*maxval);
            minval=min(nums[i],minval*nums[i]);
            ans=max(ans,maxval);
        }
        return ans;
    }
};
