//https://codeforces.com/contest/1365/problem/D

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 51;
const int MAXM = 51;

char maze[MAXN][MAXM];
bool reacheable[MAXN][MAXM] = {false};
bool visited[MAXN][MAXM] = {false};

int n,m;

void dfs(int x, int y){
    
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (visited[x][y])
        return;
    visited[x][y] = true;
    if (maze[x][y] == '#' || maze[x][y] == 'B'){
        reacheable[x][y] = false;
        return;
    }
    reacheable[x][y] = true;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

void solve(){
    vector<pair<int,int>> positions_g, positions_b;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        for (int j=0;j<m;j++){
            maze[i][j] = s[j];
            if (s[j] == 'G')
                positions_g.push_back({i,j});
            if (s[j] == 'B')
                positions_b.push_back({i,j});
        }
    }
    bool possible = true;
    for (auto [x,y] : positions_b){
        if (x > 0){
            if (maze[x-1][y] == 'G'){
                possible = false;
                break;
            }
            if (maze[x-1][y] == '.')
                maze[x-1][y] = '#';
        }
            
        if (x < n-1){
            if (maze[x+1][y] == 'G'){
                possible = false;
                break;
            }
            if (maze[x+1][y] == '.')
                maze[x+1][y] = '#';
        }
        if (y > 0){
            if (maze[x][y-1] == 'G'){
                possible = false;
                break;
            }
            if (maze[x][y-1] == '.')
                maze[x][y-1] = '#';
        }
        if (y < m-1){
            if (maze[x][y+1] == 'G'){
                possible = false;
                break;
            }
            if (maze[x][y+1] == '.')
                maze[x][y+1] = '#';
        }
    }
    
    dfs(n-1,m-1);

    for (auto [x,y] : positions_g)
        possible &= reacheable[x][y];
    
    possible ? cout<<"Yes\n" : cout<<"No\n";

    //Reset
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            reacheable[i][j] = visited[i][j] = false;
}

int main(){
    FASTIO
    int t;
    cin>>t;
    while(t--)
        solve();
}