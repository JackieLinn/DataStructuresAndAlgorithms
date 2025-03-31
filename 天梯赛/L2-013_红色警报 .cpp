#include <bits/stdc++.h>

using namespace std;
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<bool> del(n);
    int cur_blocks = 0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto get_blocks = [&](){
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int u){
            vis[u]=true;
            for(auto &v:g[u]){
                if(!vis[v]&&!del[v]){
                    dfs(v);
                }
            }
        };
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]&&!del[i]){
                dfs(i);
                cnt++;
            }
        }
        return cnt;
    };

    int k;
    cin>>k;
    int pre=get_blocks();
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        del[x]= true;
        int cnt = get_blocks();
        if(cnt<=pre) {
            cout << "City " << x << " is lost.\n";
        }else if(cnt>pre){
            cout<<"Red Alert: City "<<x<<" is lost!\n";
        }
        pre=cnt;
        bool flag = false;
        for(int i=0;i<n;i++){
            if(!del[i]){
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"Game Over."<<"\n";
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}