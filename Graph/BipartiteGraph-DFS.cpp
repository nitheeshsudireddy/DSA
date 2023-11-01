class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color){
        color[node] = col;
        
        for(int adjnode : graph[node]){
            // not yet colored
            if(color[adjnode] == -1){
                if(dfs(adjnode, !col, graph, color) == false){
                    return false;
                }
            }
            else if(color[adjnode] == color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        for(int i=0;i<n;i++){
            if(col[i] == -1){
                if(dfs(i, 0, graph, col) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
