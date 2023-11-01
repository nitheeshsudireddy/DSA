class Solution {
public:
    bool check(int start, vector<vector<int>>& graph, int color[] ){
        queue<int> q;
        int n = graph.size();
        q.push(start);

        color[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i: graph[node]){
                if(color[i] == -1){
                    color[i] = !color[node];
                    q.push(i);
                }
                else if(color[i] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        for(int i=0;i<n;i++) color[i] = -1;
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if( check(i,graph, color) == false ) return false;
            }
        }
        return true;
    }
};
