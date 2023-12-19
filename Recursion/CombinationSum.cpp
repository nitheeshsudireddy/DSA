class Solution {
public:
    void solve(int ind, int n, vector<int> &ds, vector<vector<int>> &res, vector<int>&nums,int sum, int target){
        if(ind == n){
            if(sum == target){
                res.push_back(ds);
            }
            return;
        }
        if(sum+nums[ind]<=target){
            ds.push_back(nums[ind]);
            solve(ind,n,ds,res,nums,sum+nums[ind],target);
            ds.pop_back();
        }
        solve(ind+1,n,ds,res,nums,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> res; 
        solve(0,n,ds,res,candidates,0,target);
        return res;
    }
};
