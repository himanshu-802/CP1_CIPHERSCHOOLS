#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll power (ll x, ll y){
	if(y==0)return 1;
	if(y%2==0)return power(x*x,y/2);
	else return x*power(x*x,y/2);
}
ll order(ll x){
	ll n=0;
	while(x!=0){
		n++;x=x/10;
	}
	return n;
}
bool isArm(ll x){
	ll n=order(x);
	ll temp=x; sum=0;
	while(!temp){
		ll r= temp%10;
		sum+=power(r,n);
		temp=temp/10;
	}
	return (sum==x);
}
int main()
{
	Armstrong obj=new Armstrong();
	ll x=100;
	cout<<obj.isArm(x);
}
