class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows = nums.size();
        unordered_map<int,vector<int>> sumMap;
        for(int row = nums.size()-1;row>=0;row--){
            for(int col = 0; col < nums[row].size();col++){
                sumMap[row+col].push_back(nums[row][col]);
            }
        }
        vector<int> ans;
        int curr = 0;
        while(sumMap.find(curr)!=sumMap.end()){
            for(auto i : sumMap[curr]){
                ans.push_back(i);
            }
            curr++;
        }
        return ans;
    }
};
