class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> map;
        int left = 0;
        int maxLen = 0;
        int right = 0;
        while(right<s.size()){
            map[s[right]]++;
            if(map.size()<=k){
                maxLen = max(maxLen, right-left+1);
            }
            while(map.size()>k){
                map[s[left]]--;
                if(map[s[left]] == 0){
                    map.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        return maxLen;
    }
};
