class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,pathVis)) return true;
            }
            else if(pathVis[it]) return true;
        }

        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        int vis[V];
        int pathVis[V];

        for(int i=0;i<V;i++){
            vis[i] = 0;
            pathVis[i] = 0;
        }
        vector<int> ans;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis);
            }
        }

        for(int i=0;i<V;i++){
            if(pathVis[i]==0) ans.push_back(i);
        }
        return ans;
    }
};
