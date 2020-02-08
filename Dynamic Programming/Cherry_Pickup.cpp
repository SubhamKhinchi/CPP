class Solution {
    
public:
    vector<vector<int> > g;
    int dp[50][50][50];
    int dpfunction(int r1, int c1, int c2, int N){
        int r2=r1+c1-c2;
        if(r1>=N || c1>=N || r2>=N ||c2>=N || g[r1][c1]==-1 || g[r2][c2]==-1){
            return INT_MIN;
        }
        if(dp[r1][c1][c2]!=-1){
            return dp[r1][c1][c2];
        }
        if(r1==N-1 && c1==N-1){
            return g[r1][c1];
        }
        int ans=g[r1][c1];
        if(c1!=c2){
            ans+=g[r2][c2];
        }
        int temp = max(dpfunction(r1,c1+1,c2+1,N), dpfunction(r1,c1+1,c2,N));
        temp = max(temp, dpfunction(r1+1,c1,c2+1,N));
        temp = max(temp, dpfunction(r1+1,c1,c2,N));
        ans+=temp;
        return dp[r1][c1][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        g=grid;
        memset(dp,-1,sizeof(dp));
        return max(0, dpfunction(0,0,0,n));
    }
};