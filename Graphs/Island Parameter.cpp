class Solution {
public:
    int R,C,ans;
    bool isOut(int i,int j){
        return i<0||R<=i||j<0||C<=j;
    }
    void dfs(vector<vector<int>>& a,int i,int j)
    {
        a[i][j]=2;                         
        for(auto p:{-1,1}){
            if(isOut(i+p,j)||a[i+p][j]==0)ans++;
            else if(a[i+p][j]==1)dfs(a,i+p,j);  
            if(isOut(i,j+p)||a[i][j+p]==0)ans++;
            else if(a[i][j+p]==1)dfs(a,i,j+p);
        }
    }

    int islandPerimeter(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        R=a.size(),C=a[0].size(),ans=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
                if(a[i][j]==1){             
                    dfs(a,i,j);
                    return ans;
                }
        }
        return ans;
    }
};
