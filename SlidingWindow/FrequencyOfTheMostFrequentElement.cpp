class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = INT_MIN;
        int left = 0;
        long long int curr = 0;
        for(int right=0;right<nums.size();right++){
            long int target = nums[right];
            curr += target;
            while((right-left+1)*target-curr > k){
                curr -= nums[left];
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
