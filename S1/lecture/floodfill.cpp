#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

int grid[MAXN][MAXM]; // the grid itself
int n, m; // grid dimensions, rows and columns
bool visited[MAXN][MAXM]; // keeps track of which nodes have been visited
int currentSize = 0; // reset to 0 each time we start a new component
void floodfill(int r, int c, int color){
    if(r < 0 || r >= n || c < 0 || c >= m) return; // if outside grid
    if(grid[r][c] != color) return; // wrong color
    if(visited[r][c]) return; // already visited this square

    visited[r][c] = true; // mark current square as visited
    currentSize++; // increment the size for each square we visit
    // recursively call floodfill for neighboring squares
    floodfill(r, c+1, color);
    floodfill(r, c-1, color);
    floodfill(r-1, c, color);
    floodfill(r+1, c, color);
}


int main(){
    /**
    * input code and other problem-specific stuff here
    */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                currentSize = 0;
                floodfill(i, j, grid[i][j]);
                // start a floodfill if the square hasn't
                // already been visited, and then
                // store or otherwise use the component size for whatever
                // it's needed for
            }
        }
    }
    return 0;
}
