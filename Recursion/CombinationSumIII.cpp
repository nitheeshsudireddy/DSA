class Solution {
public:
    void solve(int ind, int n, int k, int sum, int target, vector<int> &ds, vector<vector<int>>&res, vector<int> &nums){
        if(sum == target){
            if( ds.size() == k){
                res.push_back(ds);
            }
            return;
        }
        if(ind == n) return;
        if(sum+nums[ind]<=target){
            ds.push_back(nums[ind]);
            solve(ind+1,n,k,sum+nums[ind],target,ds,res,nums);
            ds.pop_back();
        }
        solve(ind+1,n,k,sum,target,ds,res,nums);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> ds;
        solve(0,9,k,0,n,ds,res, nums);
        return res;
    }
};
