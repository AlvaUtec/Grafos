// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5+1;
const int MAXM = 1e5+1;
int n,m;
vector<int> adj[MAXN];
bool visited[MAXN] = {false};


void dfs(int u){
    if (visited[u])
        return;
    
    visited[u] = true;
    for (auto v : adj[u])
        dfs(v);
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans=0;
    vector<int> representatives;

    for(int i=1;i<=n;i++){
        if (!visited[i]){
            ans++;
            representatives.push_back(i);
            dfs(i);
        }
    }
    int sz = representatives.size();
    cout<<ans-1<<"\n";
    for(int i=1;i<sz;i++)
        cout<<representatives[i-1]<<" "<<representatives[i]<<"\n";
    
}

int main(){
    FASTIO;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}