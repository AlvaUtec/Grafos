//https://codeforces.com/contest/862/problem/B

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ull unsigned long long

const int MAXN = 1e5;
const int mod = 1e9 + 7;

using namespace std;

vector<int> adj[MAXN];

ll c1=0,c2=0;

//dfs para el coloreo
void dfs(int curr, int parent, bool color){
    (color ? c1: c2)++;

    for(int u : adj[curr]){
        if (u != parent)
            dfs(u, curr, !color);
    }
}

void solve(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0);

    ll ans = c1 * c2 -(n-1);
    cout<<ans<<"\n";
}

int main(){
    FASTIO;
    int t;
    //cin >> t;
    t=1;
    while (t--)
        solve();
}