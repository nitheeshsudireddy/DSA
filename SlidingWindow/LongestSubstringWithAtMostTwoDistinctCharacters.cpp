class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        set<char> set;
        int maxLen = INT_MIN;
        int len = 0;
        char prev2;
        char prev1;
        int p2 = -1;
        int p1 = -1;
        for(int i=0;i<s.length();i++){
            if(p2 == -1 || s[i]==prev2){
                prev2 = s[i];
                p2 = i;
            }
            else if(p1 == -1 || s[i] == prev1){
                prev1 = s[i];
                p1 = i;
            }
            else{
                maxLen = max(maxLen, max(p1,p2)-len+1);
                len = min(p1,p2)+1;
                p2 = max(p1,p2);
                prev2 = s[p2];
                p1 = i;
                prev1 = s[i];
            }
        }
        maxLen = max(maxLen, max(p1,p2)-len+1);
        return maxLen;
    }
};
