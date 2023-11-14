class Solution {
public:
    bool possible(vector<int>& weights, int capacity, int days){
        int cnt = 0;
        int totalDays = 0;
        for(int i=0;i<weights.size();i++){
            if(cnt+weights[i]>capacity){
                totalDays++;
                cnt = weights[i];
            }
            else{
                cnt += weights[i];
            }
        }
        if(cnt <= capacity) totalDays++;
        if(totalDays <= days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            maxi = max(maxi,weights[i]);
        }
        int low = maxi;
        int high = sum;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(weights,mid,days)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
