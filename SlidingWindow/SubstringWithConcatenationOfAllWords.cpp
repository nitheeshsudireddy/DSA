class Solution {
public:
    bool isPossible(string s, unordered_map<string,int> map,int len){
        for(int j=0; j<s.size(); j+=len) {
            string w = s.substr(j, len);
            if(map.find(w) != map.end()) map[w]--;
            else {
                return false;
            }
        }
        for(auto i:map){
            if(i.second != 0) return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int w = words.size();
        int wsize = words[0].size();
        int subLen = wsize*w;
        int j = 0;
        vector<int> ans;
        unordered_map<string,int> map;
        for(int i=0;i<words.size();i++){
            map[words[i]]++;
        }
        int last = s.size()-subLen;
        while(j<= last ){
            if(isPossible(s.substr(j,subLen),map,wsize))ans.push_back(j);
            j++;
        }
        return ans;
    }
};
