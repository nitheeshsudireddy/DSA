class Solution {
public:
    int characterReplacement(string s, int k) {
        int freqMap[26];
        memset(freqMap,0,sizeof(freqMap));
        int maxLen = 0;
        int start = 0;
        int end = 0;
        int maxFreq = 0;
        for(int end=0;end<s.length();end++){
            freqMap[s[end]-'A']++;
            maxFreq = max(maxFreq, freqMap[s[end]-'A']);
            if (end + 1 - start - maxFreq > k) {
                freqMap[s[start]-'A'] -= 1;
                start += 1;
            }
            maxLen = max(maxLen,end + 1 - start);
        }
        return maxLen;
    }
};
