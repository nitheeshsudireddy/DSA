class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<long long> copyNums(nums.begin(),nums.end());
        int count = 0;
        while(left < right) {
            if(copyNums[left] == copyNums[right]) {
                left++;
                right--;
            }else if(copyNums[left] > copyNums[right]) {
                copyNums[right-1] += copyNums[right];
                right--;
                count++;
            }else {
                copyNums[left+1] += copyNums[left];
                left++;
                count++;
            }
        }
        return count;
    }
};
