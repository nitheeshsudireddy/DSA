class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int left = 0;
        int zeros = 0;
        int maxLen = 0;
        int lastZero = -1;
        for(int right=0;right<nums.size();right++){
            if(nums[right] == 0){
                zeros++;
            }
            if(zeros<=1){
                maxLen = max(maxLen,right-left+1);
            }
            while(zeros > 1){
                if(nums[left] == 0) zeros--;
                left++;
            }
        }
        return maxLen;
    }
};
