class Solution {
public:
    long long int fun(vector<int> &piles, int perHour){
        long long int totalTime = 0;
        for(auto i: piles){
            totalTime += i/perHour;
            if(i%perHour != 0) totalTime++;
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = -1;
        for(auto i:piles){
            maxi = max(maxi,i);
        }
        long long int ans = maxi;
        int low = 1;
        int high = maxi;
        while(low<=high){
            long long int mid = (low+high)/2;
            if(fun(piles,mid)>h){
                low = mid+1;
            }
            else{
                ans = min(ans,mid);
                high = mid-1;
            }
        }
        return ans;
    }
};
