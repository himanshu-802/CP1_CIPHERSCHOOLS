class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ex) {
        int n=candies.size();
        vector<bool>ans;
        if(n==0)return ans;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(candies[i],maxi);
        }
        for(int i=0;i<n;i++)
        {
            if(candies[i]+ex>=maxi){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
     return ans;   
    }
};
