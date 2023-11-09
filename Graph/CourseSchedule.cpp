class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> inDegree(numCourses,0);
        vector<int> adj[numCourses];
        for(auto i: prerequisites)
        {
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
        }
        for(auto p: prerequisites){
            inDegree[p[0]]++;
        }
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i: adj[node]){
                inDegree[i]--;
                if(inDegree[i] == 0) q.push(i);
            }
        }
        if(ans.size() == numCourses )return true;
        return false;
    }
};
