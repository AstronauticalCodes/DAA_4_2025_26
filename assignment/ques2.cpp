#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HamiltonianCycle {
public:
    int V;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> path;

    bool isSafe(int v, int pos) {
        if (graph[path[pos - 1]][v] == 0)
            return false;

        if (visited[v])
            return false;

        return true;
    }

    bool solve(int pos) {
        if (pos == V) {
            return graph[path[pos - 1]][path[0]] == 1;
        }

        for (int v = 1; v < V; v++) {
            if (isSafe(v, pos)) {
                path[pos] = v;
                visited[v] = true;

                if (solve(pos + 1))
                    return true;

                visited[v] = false;
                path[pos] = -1;
            }
        }
        return false;
    }

    void findCycle() {
        path.assign(V, -1);
        visited.assign(V, false);

        path[0] = 0;
        visited[0] = true;

        if (!solve(1)) {
            cout << "No Hamiltonian Cycle exists" << endl;
            return;
        }

        cout << "Hamiltonian Cycle:" << endl;
        for (int i = 0; i < V; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << endl;
    }
};

int main() {
    HamiltonianCycle hc;

    cout << "\nEnter number of vertices: ";
    if (!(cin >> hc.V)) return 0;

    hc.graph.assign(hc.V, vector<int>(hc.V));

    cout << "Enter adjacency matrix (0 or 1):" << endl;
    for (int i = 0; i < hc.V; i++) {
        for (int j = 0; j < hc.V; j++) {
            cin >> hc.graph[i][j];
        }
    }

    hc.findCycle();

    return 0;
}