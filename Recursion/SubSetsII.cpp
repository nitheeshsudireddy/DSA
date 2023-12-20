class Solution {
public:
    void finds(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &res ,int n){
        res.push_back(ds);         

        for(int i = ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            finds(i+1, nums, ds, res, n);
            ds.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        finds(0,nums,ds, res,n);
        return res;
    }
};
