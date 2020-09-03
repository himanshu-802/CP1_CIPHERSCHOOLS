#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		stack<char>st;
		int n=s.size();
		bool f=1;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='{' || s[i]=='(' ||s[i]=='['){
				st.push(s[i]);
			}
			if(st.empty()){
				f=0;break;
			}
			else if(s[i]=='}'){
				if(st.top()=='{'){
					st.pop();
				}
				else{
					f=0; break;
				}
			}
			else if(s[i]==')'){
			if(st.top()=='('){
				st.pop();
			}
			else{
			 f=0; break;
			}
			}			
			else if(s[i]==']'){
				if(st.top()=='['){
					st.pop();
				}
				else{
					f=0; break;
				}
			}
			
		}
		if(f==0 || st.size()>0)cout<<"not balanced\n";
		else cout<<"balanced\n";
	}
	
}
