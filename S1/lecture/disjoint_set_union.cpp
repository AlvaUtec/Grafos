#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

int parent[MAXN]; //stores the parent nodes
void initialize(int N){
    for(int i = 0; i < N; i++)
        parent[i] = i; //initially, the root of each set is the node itself
    
}

int find(int x){ //finds the root of the set of x
    if(x == parent[x]) //if x is the parent of itself, it is the root
        return x;
    else
        return find(parent[x]); //otherwise, find the root of the parent of x
} 


void union(int a, int b){ //merges the sets of a and b
    int c = find(a); //find the root of a
    int d = find(b); //find the root of b
    if(c != d) //if they are not the same, they are in different sets
        parent[d] = c; //merge the sets by setting the parent of d to c
    
}