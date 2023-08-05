// https://cses.fi/problemset/task/1667

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

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    vector<int> parent(n+1,-1);
    parent[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
        }
    }
    if (parent[n] == -1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vector<int> path;
    int u = n;
    while(u != 0){
        path.push_back(u);
        u = parent[u];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<"\n";
    for(auto u : path)
        cout<<u<<" ";
    cout<<"\n";
}

int main(){
    FASTIO;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}