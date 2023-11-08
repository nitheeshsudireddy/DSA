class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int longest = 0;
        for(int i:s){
            if( s.find(i-1) == s.end()){
                int currentNum = i;
                int currentlen = 1;
                while(s.find(currentNum+1) != s.end()){
                    currentNum += 1;
                    currentlen++;
                }
                longest = max(longest,currentlen);
            }
        }
        return longest;
    }
};
