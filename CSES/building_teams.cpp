// https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5+1;
const int MAXM = 2e5+1;
int n,m;
vector<int> adj[MAXN];
bool visited[MAXN] = {false};
int color[MAXN] = {0};

bool dfs(int u, int parent){
    if (visited[u])
        return color[u] != color[parent];
    
    visited[u] = true;
    color[u] = !color[parent];
    bool bipartite = true;
    for(auto v : adj[u]){
        if (!visited[v])
            bipartite &= dfs(v,u);
        else
            bipartite &= color[v] != color[u];
    }
    return bipartite;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool bipartite = true;
    color[1] = 1;
    for(int i=1;i<=n;i++){
        if (!visited[i])
            bipartite &= dfs(i,0);
    }

    if (!bipartite){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(int i=1;i<=n;i++)
        cout<<color[i]+1<<" ";
}

int main(){
    FASTIO;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}