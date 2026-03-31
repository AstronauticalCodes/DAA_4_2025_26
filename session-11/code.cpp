#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& adj, vector<int>& path, int pos) {
    if (adj[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamiltonianUtil(vector<vector<int>>& adj, vector<int>& path, int pos, int n) {
    if (pos == n) {
        if (adj[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < n; v++) {
        if (isSafe(v, adj, path, pos)) {
            path[pos] = v;
            if (hamiltonianUtil(adj, path, pos + 1, n))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

void hamiltonianCycle(vector<vector<int>>& adj, int n) {
    vector<int> path(n, -1);
    path[0] = 0;
    if (hamiltonianUtil(adj, path, 1, n)) {
        cout << "Hamiltonian Cycle exists: ";
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << path[0] << endl;
    } else {
        cout << "No Hamiltonian Cycle exists" << endl;
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    hamiltonianCycle(adj, n);
    return 0;
}