class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[j]=nums[i];
                j=j+1;
            }
        }
        for(;j<nums.size();j++)
        {
            nums[j]=0;
        }
        
    }
};
