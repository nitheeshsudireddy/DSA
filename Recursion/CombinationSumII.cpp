class Solution {
public:
    void solve(int ind, vector<int> &nums, vector<vector<int>> &res, vector<int> &ds, int target, int n){
        if(target==0){
            res.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            ds.push_back(nums[i]);
            solve(i+1,nums,res,ds,target-nums[i],n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> res;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(0,candidates,res,ds,target,n);
        return res;
    }
};
