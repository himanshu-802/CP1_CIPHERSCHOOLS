class Solution {
public:
    int func(int n, vector<int>&v)
    {
        if(n==0 || n==1)return n;
        
        if(v[n]!=-1)return  v[n-1];
        
        v[n-1]= func(n-1,v)+ func(n-2,v);
        return v[n-1];
    }
    int fib(int N) {
        
        vector<int>v(35,-1);
        return func(N,v);
        
    }
};
