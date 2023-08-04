//https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1001;
const int MAXM = 1001;

char maze[MAXN][MAXM];
bool visited[MAXN][MAXM] = {false};

int n,m,ans=0;

vector<pair<int,int>> directions(int x, int y){
    vector<pair<int,int>> dirs;
    if (x > 0)
        dirs.push_back({x-1,y});
    if (x < n-1)
        dirs.push_back({x+1,y});
    if (y > 0)
        dirs.push_back({x,y-1});
    if (y < m-1)
        dirs.push_back({x,y+1});
    return dirs;
}

void visit(int i, int j){
    if (visited[i][j])
        return;
    
    visited[i][j] = true;
    if (maze[i][j] == '#')
        return;
    
    for (auto dir : directions(i,j))
        visit(dir.first,dir.second);
}

void dfs(int i, int j){
    if (visited[i][j])
        return;
    
    visited[i][j] = true;
    if (maze[i][j] == '#')
        return;
    
    ans++;
    for (auto dir : directions(i,j))
        visit(dir.first,dir.second);
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
            maze[i][j] = s[j];
    }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dfs(i,j);

    cout<<ans<<"\n";

    ans = 0;
    memset(visited,false,sizeof(visited));
}

int main(){
    FASTIO
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}