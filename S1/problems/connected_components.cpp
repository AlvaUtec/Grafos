// https://codeforces.com/problemset/problem/920/E
#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ull unsigned long long

const int MAXN = 200001;
const int mod = 1e9 + 7;

using namespace std;

unordered_set<int> not_adj[MAXN];
set<int> unvisited;
int sz[MAXN];
int curr=0;

void dfs(int v){
    sz[curr]++;
    auto it = unvisited.begin();
    while(it != unvisited.end()){
        //If no edge between v and *it
        if(not_adj[v].count(*it))
            it++;
        else{
            int u = *it;
            unvisited.erase(u);
            dfs(u);
            it = unvisited.upper_bound(u);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        not_adj[u].insert(v);
        not_adj[v].insert(u);
    }
    for(int i=1;i<=n;i++)
        unvisited.insert(i);
    for(int i=1;i<=n;i++){
        auto it = unvisited.find(i);
        if(it != unvisited.end()){
            unvisited.erase(it);
            dfs(i);
            curr++;
        }
    }
    cout<<curr<<"\n";
    sort(sz,sz+curr);
    for(int i=0;i<curr;i++)
        cout<<sz[i]<<" ";
    cout<<"\n";
}

int main(){
    FASTIO;
    int t;
    //cin >> t;
    t=1;
    while (t--)
        solve();
}