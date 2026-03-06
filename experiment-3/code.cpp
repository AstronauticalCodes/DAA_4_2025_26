class Solution {
public:
    bool checkHamiltonean(int n, int u, vector<vector<int>>& adj, int& count, vector<bool>& visited) {
        if (count == n) return true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                count++;
                if (checkHamiltonean(n, v, adj, count, visited)) return true;
                count--;
                visited[v] = false;
            }
        }
        return false;
    }

    bool check(int n, int m, vector<vector<int>> edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 1; i <= n; i++) {
            vector<bool> visited(n + 1, false);
            int count = 1;
            visited[i] = true;
            if (checkHamiltonean(n, i, adj, count, visited)) return true;
        }

        return false;
    }
};
