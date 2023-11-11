class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        while(l<h){
            int mid = l + (h-l)/2;
            bool halfseven = (h-mid)%2 == 0;
            if(nums[mid] == nums[mid+1]){
                if(halfseven){
                    l = mid+2;
                }
                else{
                    h = mid-1;
                }
            }
            else if(nums[mid-1]==nums[mid]){
                if(halfseven){
                    h = mid-2;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                return nums[mid];
            }
        }
        return nums[l];
    }
};
