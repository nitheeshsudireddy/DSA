class Solution {
  public:
    bool detect(int src, int parent, vector<int> adj[], vector<int> &vis){
        vis[src] = 1;
        for(auto node:adj[src]){
            if(!vis[node]){
                if(detect(node,src,adj,vis)) return true;;
            }
            else if(parent != node) return true;
            
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if( detect(i,-1,adj,vis) ) return true;
            }
        }
        return false;
    }
};
