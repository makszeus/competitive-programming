class Solution {
public:

        bool dfsCycle(int v, std::vector<std::vector<int>>& graph, std::vector<int>& state, std::vector<int>& st) {
        state[v] = 1;
        for (const auto &u : graph[v]) {
            if (state[u] == 1) return true;
            if (state[u] == 0 && dfsCycle(u, graph, state, st)) return true;
        }
        state[v] = 2;
        st.push_back(v);
        return false;
    }

    std::vector<int> topologicalSort(int n, std::vector<std::vector<int>>& graph) {
        std::vector<int> state(n, 0);
        std::vector<int> st;

        for (int i = 0; i < n; ++i) {
            if (state[i] == 0 && dfsCycle(i, graph, state, st)) {
                return {};
            }
        }
        reverse(st.begin(), st.end());
        return st;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        for (auto &edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            graph[prereq].push_back(course);
        }
        return topologicalSort(numCourses, graph);
    }
};