class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int temp=target-nums[i];
            if(mp.find(temp)!=mp.end() && mp[temp]!=i){
                v.push_back(i);
                v.push_back(mp[temp]);
                break;
            }
            
        }
        return v;
    }
};
