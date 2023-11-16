class Solution {
public:
    bool isPossible(vector<int>& position, int dist,int m){
        int balls = 1;
        int last = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last >= dist){
                balls++;
                last = position[i];
            }
        }
        if(balls>=m) return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int range = position[n-1]-position[0];
        int ans = INT_MIN;
        int low = 1;
        int high = range;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(position,mid,m)){
                ans = max(ans,mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};
