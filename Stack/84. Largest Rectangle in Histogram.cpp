class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        
        stack<int>st;
        int n=arr.size();
        int maxi=0,i;
        for(i=0;i<n;)
        {
            if(st.empty() || arr[i]>= arr[st.top()]){
                st.push(i);
                i++;
                continue;
            }
            else{
                int tp=arr[st.top()]; st.pop();
                int ans;
                if(st.empty()){
                    ans= tp*i;
                }
                else{
                    ans= tp*(i- st.top()-1);
                }
                maxi=max(maxi,ans);
            }
        }
        while(!st.empty()){
            int tp=arr[st.top()]; st.pop();
            int ans;
            if(st.empty()){
                ans=tp*(i);
            }
            else{
                ans= tp* (i-st.top()-1);
            }
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};
