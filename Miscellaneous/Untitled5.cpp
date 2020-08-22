#include<bits/stdc++.h>
using namespace std;
void func(vector<int>v, int n, int sum, vector<int>ans,vector<int>&vis)
{
	if(sum==0)
	{
	    for(int i=0;i<ans.size();i++)
	    {
	    	cout<<v[ans[i]]<<" ";
	    	vis[ans[i]]=-1;
		}
		cout<<endl;
		return;
		
	}
	if(n==0 && sum!=0){
		return ;
	}
	if(v[n-1]>sum){
		 func(v,n-1,sum,ans,vis);
		 return;
	}
	func(v,n-1,sum,ans,vis);
  if(vis[n-1]!=-1)	{
  ans.push_back(n-1);
	func(v,n-1,sum-v[n-1],ans,vis);}
	
}
int main()
{
	int n;cin>>n;
	int k; cin>>k;
	vector<int>v;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		sum+=x;
		v.push_back(x);
	}
	vector<int>vis(n,0);
	sum=sum/k;
	sort(v.begin(),v.end());
	vector<int>ans;
	cout<<"sum is "<<sum<<endl;
	func(v,n,sum,ans ,vis);//cout<<"1";
}
