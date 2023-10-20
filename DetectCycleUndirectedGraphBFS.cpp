class Solution {
  public:
    bool detect(int src, vector<int> adj[], int vis[]){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int adjNode: adj[node]){
                if(!vis[adjNode]){
                    q.push({adjNode,node});
                    vis[adjNode] = 1;
                }
                else if(parent != adjNode){
                    return true;
                }
            }
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }
};
