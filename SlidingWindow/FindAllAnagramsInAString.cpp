class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> pmap;
        map<char,int> smap;
        vector<int> ans;
        if(s.length()<p.length()) return ans;
        for(auto i : p){
            pmap[i-'a']++;
        }
        int left = 0;
        int right = 0;
        while(right<s.size()){
            smap[s[right]-'a']++;
            if(right>=p.size()){
                smap[s[left]-'a']--;
                if(smap[s[left]-'a'] == 0) smap.erase(s[left]-'a');
                left++;
            }
            if(smap==pmap){
                ans.push_back(left);     
            }
            right++;
        }
        return ans;
    }
};
