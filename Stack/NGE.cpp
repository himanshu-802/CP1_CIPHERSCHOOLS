class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        map<int,int>mp;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())st.push(nums2[i]);
            
            while(!st.empty() && nums2[i]>st.top())
            {
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        vector<int>v;
        for(int i=0;i<nums1.size();i++)
        {
            v.push_back(mp[nums1[i]]);
        }
        return v;
    }
};
