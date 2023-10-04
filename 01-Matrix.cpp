class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
	    int m = mat[0].size();
	    vector<vector<int>> result(n, vector<int>(m,0));
	    queue<pair<pair<int,int>, int>> q;
	    vector<vector<int>> vis(n, vector<int>(m,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(mat[i][j] == 0){
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    int delrow[] = {-1,0,1,0};
	    int delcol[] = {0,-1,0,1};
	    while(!q.empty()){
	        int nodei = q.front().first.first;
	        int nodej = q.front().first.second;
	        int d = q.front().second;
	        if(result[nodei][nodej] != 0 ) result[nodei][nodej] = min(result[nodei][nodej],d);
	        else result[nodei][nodej] = d;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int ni = nodei + delrow[i];
	            int nj = nodej + delcol[i];
	            
	            if(ni<n && nj<m && ni>=0 && nj>=0 && !vis[ni][nj] && mat[ni][nj] == 1){
	                q.push({{ni,nj},d+1});
	                vis[ni][nj] = 1;
	            }
	        }
	        
	    }
	    return result;
        
    }
};
