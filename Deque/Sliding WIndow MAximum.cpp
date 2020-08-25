class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int B=k;
         vector<int>A;
        A=nums;
        int n=A.size();
       
vector<int>ans;
ans.resize(n-B+1);
if(n<B)return ans;
deque<int>dq;
for(int i=0;i<B;i++)
{
    while(!dq.empty() && A[i]>=A[dq.back()])
    {
        dq.pop_back();
    }
    dq.push_back(i);
}
for(int i=B;i<n;i++)
{
    ans[i-B]=A[dq.front()];
    while(!dq.empty() && A[i]>=A[dq.back()])
    {
        dq.pop_back();
    }
    while(!dq.empty() && dq.front() <= i-B){
        dq.pop_front();
    }
    
    dq.push_back(i);
}
ans[n-B]=A[dq.front()];
return ans;
    }
};
