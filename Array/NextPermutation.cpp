class Solution {
public:
    void reverse(vector<int> &nums, int start){
        int end = nums.size()-1;
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        if(i>=0){
            int j = n-1;
            while(j>i && nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums,i+1);
        
    }
};
