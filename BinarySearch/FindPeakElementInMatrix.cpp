class Solution {
public:
    int findMax(vector<vector<int>>& mat, int col){
        int maxi = INT_MIN;
        int row = -1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                row = i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> ans;
        int low = 0;
        int high = c-1;
        while(low<=high){
            int mid = (low+high)/2;
            int row = findMax(mat,mid);
            int left = mid-1>=0 ? mat[row][mid-1] : -1;
            int right = mid+1<c ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid] < left)
                    high = mid-1;
            else low = mid+1;   
        }
        return ans;
    }
};
