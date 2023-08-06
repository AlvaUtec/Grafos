// https://cses.fi/problemset/task/1669

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5+1;
const int MAXM = 2e5+1;


int n,m, sv, ev;
vector<int> parent, visited;
vector<vector<int>> adj;

bool dfs(int u, int p){
    visited[u] = true;
    parent[u] = p;
    for (auto v : adj[u]){
        if (v == p)
            continue;
        
        if (visited[v]){
            sv = v;
            ev = u;
            return true;
        }

        if(!visited[v])
            if(dfs(v,u))
                return true;
    }
    return false;
}

bool visiting(){
    for(int i=1;i<=n;i++)
        if (!visited[i])
            if (dfs(i,-1))
                return true;
    return false;
}

void solve(){
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1);
    parent.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (!visiting())
        cout<<"IMPOSSIBLE\n";
    else{
        int tv = ev;
        vector<int> path;
        path.push_back(ev);
        while(tv != sv){
            path.push_back(parent[tv]);
            tv = parent[tv];
        }
        path.push_back(ev);
        cout<<path.size()<<"\n";
        for(auto u : path)
            cout<<u<<" ";
        cout<<"\n";
    }
}

int main(){
    FASTIO;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}