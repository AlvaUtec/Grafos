//https://cses.fi/problemset/task/1682

// La solución es que para cualquier nodo, 
//exista un ciclo que recorra todos los nodos y regrese a él mismo.

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ull unsigned long long

const int MAXN = 1e5;
const int MAXM = 2e5;
const int mod = 1e9 + 7;

using namespace std;

vector<int> adj[MAXN][2];
bool visited[MAXN];

void dfs(int v, int x){
    visited[v] = true;
    for(int u : adj[v][x]){
        if(!visited[u])
            dfs(u,x);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][0].push_back(v);
        adj[v][1].push_back(u);
    }
    dfs(0,0);
    for(int i=0;i<n;i++){
        if (!vis[i]){
            cout<<"NO\n"<<1<<" "<<i+1<<"\n";
            return;
        }
    }

    // Memset inicializa con 0 todos los valores de visites, o sea, reset
    memset(visited,0,sizeof(visited));
    dfs(0,1);
    for(int i=0;i<n;i++){
        if (!vis[i]){
            cout<<"NO\n"<<i+1<<" "<<1<<"\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    FASTIO;
    int t;
    //cin >> t;
    t=1;
    while (t--)
        solve();
}