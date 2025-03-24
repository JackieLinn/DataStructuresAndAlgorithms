#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5+10;
void solve(){
    int n;
    cin>>n;
    vector<int> p(N+1,0);
    iota(p.begin(),p.end(),0ll);
    map<int,int> mp;
    function<int(int)> find = [&](int x){
        if(x!=p[x]){
            p[x]=find(p[x]);
        }
        return p[x];
    };
    auto merge = [&](int x,int y){
        x=find(x),y=find(y);
        if(x==y){
            return false;
        }
        p[y]=x;
        return true;
    };
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<int> a;
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
            mp[x]++;
            a.push_back(x);
        }
        for(int i=0;i<a.size()-1;i++){
            merge(a[i],a[i+1]);
        }
    }
    int q;
    cin>>q;
    int tot=0;
    for(auto &[v,w]:mp){
        tot++;
    }
    cout<<tot<<" ";
    int cnt=0;
    for(auto &[v,w]:mp){
        if(v==find(v)){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if(find(x)==find(y)) cout<<"Y"<<"\n";
        else cout<<"N"<<"\n";
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