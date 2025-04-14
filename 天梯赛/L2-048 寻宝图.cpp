#include<bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(int j=1;j<=m;j++){
            mp[i][j]=str[j-1]-'0';
        }
    }
    int cnt=0;
    int cnt_wt=0;
    vector<vector<int>> vis(n+1,vector<int>(m+1,0));
    auto bfs = [&](int i,int j){
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        queue<pii> q;
        q.push({i,j});
        vis[i][j]=true;
        cnt++;
        bool flag=false;
        if(mp[i][j]>1){
            flag=true;
        }
        while(q.size()){
            auto a = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x=a.first+dx[k];
                int y=a.second+dy[k];
                if(x>=1&&x<=n&&y>=1&&y<=m&&!vis[x][y]&&mp[x][y]!=0){
                    vis[x][y]=true;
                    if(mp[x][y]>1){
                        flag=true;
                    }
                    q.push({x,y});
                }
            }
        }
        if(flag){
            cnt_wt++;
        }
    };

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]&&mp[i][j]!=0){
                bfs(i,j);
            }
        }
    }
    cout<<cnt<<" "<<cnt_wt<<"\n";
}
signed main() {
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}
