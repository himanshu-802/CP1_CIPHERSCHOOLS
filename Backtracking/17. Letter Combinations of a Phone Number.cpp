class Solution {
public:
   
    void func(string str,vector<string>&ans)
    {
        string table[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        queue<string>q;
        q.push("");
        while(!q.empty())
        {
            string u=q.front();
            q.pop();
            if(u.size()==str.size())
            {
                ans.push_back(u);
            }
            else{
              for(auto i:table[str[u.size()]-'0']){
                 q.push(u+i);
              }
            }
        }
    }
    vector<string> letterCombinations(string digits) {
      
        vector<string>ans;
          if(digits.size()==0)return ans;
        func(digits,ans);
        return ans;
    }
};
