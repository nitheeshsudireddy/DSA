class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right  = 0;
        int ans = 0;
        unordered_map<char,int> map;
        for(int right=0;right<s.size();right++){
            map[s[right]]++;
            while(map['a'] && map['b'] && map['c']){
                // no of substrings which contain (s[left] to s[right])
                ans += s.size()-right;
                map[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};
