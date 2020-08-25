class Solution {
public:
    string func(string s1, string s2)
    {
        string res;
        int n1=s1.size(), n2=s2.size();
        for(int i=0,j=0;i<=n1 && j<=n2 ;i++,j++)
        {
            if(s1[i]!=s2[j]){
                break;
            }
            res.push_back(s1[i]);
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& str) {
    int n = str.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(str), end(str));
        string a = str[0];
        string b = str[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};
