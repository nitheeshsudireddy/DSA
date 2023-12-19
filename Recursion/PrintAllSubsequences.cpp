class Solution {
public:
    void solve(int ind, int n, vector<int>& nums,vector<int>&ds, vector<vector<int>>&res){
        if(ind==n) {
            res.push_back(ds);
            return;
        }
        //Take
        ds.push_back(nums[ind]);
        solve(ind+1,n,nums,ds,res);
        //Not Take
        ds.pop_back();
        solve(ind+1,n,nums,ds,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        int n = nums.size();
        solve(0,n,nums,ds,res);
        return res;
    }
};
