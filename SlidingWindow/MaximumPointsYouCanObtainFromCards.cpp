class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalScore = 0;
        for(auto i : cardPoints) totalScore += i;
        if(k==n) return totalScore;
        int minScore = INT_MAX;
        int left = 0;
        int presentScore = 0;
        // find a min sum contigous subarray with len n-k
        // This means the sum of the rest k len array will be max.
        for(int right=0;right<n;right++){
            presentScore += cardPoints[right];
            int currLen = right-left+1;
            if(currLen == n-k){
                minScore = min(minScore,presentScore);
                presentScore -= cardPoints[left++];
            }
        }
        return totalScore - minScore;
    }
};
