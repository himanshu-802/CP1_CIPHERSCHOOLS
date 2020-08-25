class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        bool f=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(i);
                f=1;
            }
            else{
                cout<<st.top()<<endl;
                if(s[i]==')' && st.empty()==false && s[st.top()]=='(')st.pop();
                else if(s[i]=='}' && st.empty()==false &&  s[st.top()]=='{')st.pop();
                else if(s[i]==']' && st.empty()==false && s[st.top()]=='[')st.pop();
            }
        }
        if(!st.empty())return false;
        if(f==0)return false;
        return true;
    }
};
