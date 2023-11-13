class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int b = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day) cnt++;
            else{
                b += cnt/k;
                cnt = 0;
            }
        }
        b += cnt/k;
        if(b<m) return false;
        return true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto i : bloomDay){
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
        int ans = INT_MAX;
        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(bloomDay,mid,m,k)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(ans == INT_MAX ) return -1;
        return ans;
    }
};
