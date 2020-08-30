void dfs(stack<int>&st,int vis[], vector<vector<int>>adj, int u)
{
    vis[u]=1;
    for(auto i:adj[u]){
        if(vis[i]!=0){
            dfs(st,vis,adj,i);
        }
    }
    st.push(u);
}
string findOrder(string dict[], int N, int k) {
    stack<int>st;
    vector<vector<int>>adj(k+1,vector<int>());
    int* vis=new int[k];
    for(int i=0;i<k;i++)
    {
        vis[i]=0;
    }
    for(int i=0;i<N-1;i++)
    {
        string s1=dict[i];
        string s2=dict[i+1];
        for(int j=0;j<min(s1.size(),s2.size());j++)
        {
           // cout<<s1[j]-'a'<<" ";
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
}
    for(int i=0;i<k;i++)
    {
        if(vis[i]==0)
        {
            dfs(st,vis,adj,i);
        }
}
    string temp="";
    while(!st.empty())
    {
        temp+= char(st.top()+'a');
       // cout<<st.top()<<" ";st.pop();
    }
    //cout<<"temp is "<<temp<<endl;
    return temp;
}
