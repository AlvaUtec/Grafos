// https://codeforces.com/problemset/problem/1176/E

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ull unsigned long long

const int MAXN = 1e5;
const int mod = 1e9 + 7;

using namespace std;

// vector<int> adj[MAXN];
// bool visited[MAXN];
// bool color[MAXN];
// vector<int> c1,c2;

void dfs(int v, bool x, vector<int> adj[], vector<bool> &visited, vector<bool> &color, vector<int> &c1, vector<int> &c2){
    visited[v] = true;
    color[v] = x;
    if(x) c1.push_back(v);
    else c2.push_back(v);
    for(int u : adj[v]){
        if(!visited[u])
            dfs(u,!x,adj,visited,color,c1,c2);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    vector<bool> color(n+1, false);
    vector<bool> visited(n+1, false);
    vector<int> c1,c2;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,1,adj,visited,color,c1,c2);

    if (c1.size() < c2.size()){
        cout<<c1.size()<<"\n";
        for(int i=0;i<c1.size();i++)
            cout<<c1[i]<<" ";
    }
    else{
        cout<<c2.size()<<"\n";
        for(int i=0;i<c2.size();i++)
            cout<<c2[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    FASTIO;
    int t;
    cin >> t;
    //t=1;
    while (t--)
        solve();
}