class Solution {
public:

    bool cycle_detection_using_DFS(int node,
                                   vector<vector<int>>& graph,
                                   vector<bool>& visited,
                                   vector<bool>& recPath) {

        visited[node] = true;
        recPath[node] = true;

        for (int neighbor : graph[node]) {

            if (!visited[neighbor]) {

                if (cycle_detection_using_DFS(neighbor,
                                              graph,
                                              visited,
                                              recPath)) {
                    return true;
                }
            }
            else if (recPath[neighbor]) {
                return true;
            }
        }

        recPath[node] = false;

        return false;
    }

    void Topo_Sort(int node,
                   vector<vector<int>>& graph,
                   vector<bool>& visited,
                   stack<int>& s) {

        visited[node] = true;

        for (int neighbor : graph[node]) {

            if (!visited[neighbor]) {
                Topo_Sort(neighbor, graph, visited, s);
            }
        }

        s.push(node);
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(n);

        for (auto prerequisite : prerequisites) {

            int course = prerequisite[0];
            int requiredCourse = prerequisite[1];

            graph[requiredCourse].push_back(course);
        }

        vector<bool> visited(n, false);
        vector<bool> recPath(n, false);

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                if (cycle_detection_using_DFS(i,
                                              graph,
                                              visited,
                                              recPath)) {
                    return {};
                }
            }
        }

        stack<int> s;

        visited.assign(n, false);

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                Topo_Sort(i, graph, visited, s);
            }
        }

        vector<int> ans;

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};