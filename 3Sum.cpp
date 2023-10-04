class Solution {
public:
    int findTriplets(int ind, int n, vector<int> &nums, vector<vector<int>> &res){
        int low = ind+1;
        int high = n-1;
        while(low<high){
            int sum = nums[ind] + nums[low] + nums[high];
            if(sum == 0){
                res.push_back({nums[ind],nums[low],nums[high]});
                low++;
                high--;
                while(low<high && nums[low-1] == nums[low]){
                    low++;
                }
            }
            else if(sum<0) low++;
            else high--;
        }
        return 0;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size() && nums[i]<=0;i++){
            if(i == 0 || nums[i-1] != nums[i]){
                findTriplets(i,nums.size(),nums,res);
            }
        }
        return res;
    }
};
