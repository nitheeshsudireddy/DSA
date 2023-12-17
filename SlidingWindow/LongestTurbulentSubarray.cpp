class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxLen = 1;
        int left = 0;
        int prev = -1;
        int prevEl = arr[0];
        int curr;
        for(int right=1;right<arr.size();right++){
            //if adjacent elements are equal: left = right
            if(arr[right] == prevEl){
                prev = -1;
                left = right;
                continue;
            }
            // 0 for decreasing and 1 for increasing
            curr = prevEl > arr[right] ? 0 : 1;
            if(curr == prev){
                left = right-1;
            }
            maxLen = max(maxLen,right-left+1);
            prevEl = arr[right];
            prev = curr;
        }
        return maxLen;
    }
};
