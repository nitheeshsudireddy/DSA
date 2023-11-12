class Solution {
public:
    static bool compare(pair<int,int> &a, pair<int,int> &b){
        return a.second>b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> pairs;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            pairs.push_back({nums1[i],nums2[i]});
        }
        sort(pairs.begin(),pairs.end(),compare);
        priority_queue<int, vector<int>, greater<int>> topK;
        long long int topKSum = 0;
        for(int i=0;i<k;i++){
            topK.push(pairs[i].first);
            topKSum += pairs[i].first;
        }
        long long ans = topKSum * pairs[k-1].second;
        for(int i=k;i<n;i++){
            topKSum += pairs[i].first - topK.top();
            topK.pop();
            topK.push(pairs[i].first);
            ans = max(ans, (long long)topKSum*pairs[i].second);
        }
        return ans;
    }
};
