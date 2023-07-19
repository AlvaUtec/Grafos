#include <iostream>
#include <vector>
using namespace std;

const int kMaxN = 1e5+1;

// vertex[i] - which nodes share an edge with node i
vector<int> vertex[kMaxN];

bool visited[kMaxN];
// find all edges which are not in the DFs tree
int parent[kMaxN];

// list of all edges that are not in the DFs tree
vector<pair<int, int>> free_edges;

void Df(int node) {
    visited[node] = true;
    for (auto itr : vertex[node]) {
        if (itr == parent[node]) {
            continue;
        }

        if (not visited[itr]) {
            parent[itr] = node;
            Df(itr);
        } else {
            if (itr < node) {
                free_edges.push_back({node, itr});
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i += 1) {
        int a, b; cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }

    // get the number of connected components are a node from every component
    // the node will be stored in root_nodes[]
    vector<int> root_nodes;
    for (int i = 1; i <= n; i += 1) {
        if (not visited[i]) {
            root_nodes.push_back(i);
            Df(i);
        }       
    }

    // if the number of components - 1 is > number of free_edges, we don't
    // have a solution. PS: number of free_edges is 
    // M - N + number_of_components(root_nodes.size())
    if ((int)root_nodes.size() - 1 > (int)free_edges.size()) {
        cout << "-1\n";
        return 0;
    } else {
        // we need number_of_components - 1 edges to make the graph connected
        cout << (int)root_nodes.size() - 1 << '\n';

        while ((int)root_nodes.size() > 1) {
            // the the first node from root_nodes and a node from the back.
            // all the nodes will be linked with the first node.
            // it's possible to get any 2 nodes from the vector, like them,
            // and put one back.
            int a = root_nodes.front();
            int b = root_nodes.back();
            root_nodes.pop_back();
            
            // get one free 
            auto deleted_edge = free_edges.back();
            free_edges.pop_back();

            cout << deleted_edge.first << ' ' << deleted_edge.second << ' ' << a << ' ' << b << '\n';
        }
    }
    return 0;
}
