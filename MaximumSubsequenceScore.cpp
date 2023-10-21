class Solution {
public:
    static bool compare(pair<int,int> &a, pair<int,int> &b){
        return a.second>b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> temp;
        int n = nums2.size();
        for(int i=0;i<n;i++){
            temp.push_back({nums1[i],nums2[i]});
        }
        sort(temp.begin(),temp.end(), compare);

        priority_queue<int, vector<int>, greater<int>> topK;

        long long int topKSum = 0;
        for(int i=0;i<k;i++){
            topK.push(temp[i].first);
            topKSum += temp[i].first;
        }

        long long ans = topKSum * temp[k-1].second;

        for(int i=k;i<n;i++){

            topKSum += temp[i].first - topK.top();
            topK.pop();
            topK.push(temp[i].first);

            ans = max(ans, topKSum*temp[i].second);
        }

        return ans;

    }
};
