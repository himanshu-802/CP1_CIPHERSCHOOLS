class Solution {
public:
    
    bool isEqual(vector<int>& v1, vector<int>& v2){
        if(v1.size() != v2.size()) return false;
        unordered_map<int, int>m;
        for(auto x: v1) m[x]++;
        for(auto x: v2) if(--m[x] < 0) return false;
        return true;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int pos, vector<int>comb){
        if(pos >= nums.size()){
            for(auto x: res) if(isEqual(x, comb)) return;
            res.push_back(comb);
            return;
        }
        backtrack(res, nums, pos + 1, comb);
        comb.push_back(nums[pos]);
        backtrack(res, nums, pos + 1, comb);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        backtrack(res, nums, 0, vector<int>());
        return res;
    }
};
